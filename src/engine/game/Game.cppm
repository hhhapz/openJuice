/**
 * @file Game.cppm
 * @brief Module file for game operations.
 *
 * This file contains the implementation of the game operations, including state management
 * and thread-safe access to game components.
 */

module;

#include <format>

export module engine.game.Game;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.concurrency;
import std.io;
import std.fmt;
import std.mem;
import std.text;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.concurrency;
import stdlib.io;
import stdlib.fmt;
import stdlib.mem;
import stdlib.text;
#endif

import card.HyperCardFactory;
import card.StandardCardFactory;
import chat.Chat;
import engine.board.Board;
import engine.entity.Mob;
import engine.entity.Player;
import engine.game.EntityComponentSystem;
import engine.game.ecs.Components;
import engine.game.ecs.Systems;
import engine.managers.GlobalSettings;
import engine.unit.Character;
import engine.unit.Enemy;
import engine.unit.Unit;
import engine.utility.Colours;
import engine.utility.EngineUtility;
import engine.utility.GameInfo;
import unit.BasicEnemyFactory;
import unit.BossEnemyFactory;
import unit.CharacterFactory;

using namespace collections;
using namespace concurrency;
using fmt::FormatContext, fmt::FormatParseContext;
using mem::SharedPtr;

using namespace ecs;
using namespace ecs::components;
using namespace ecs::systems;

/**
 * @enum GamePhase
 * @brief Enumeration of game phases
 */
export enum class GamePhase {
    Setup,         ///< Initial game setup 
    PlayerTurn,    ///< Player taking their turn
    BattlePhase,   ///< Battle in progress
    ChapterPhase,  ///< Chapter event in progress
    EndGame,       ///< Game completed
    Paused         ///< Game paused
};

// Must use std::formatter, not fmt::Formatter
template<>
struct std::formatter<GamePhase> {
    constexpr auto parse(FormatParseContext& ctx) {
        return ctx.begin();
    }

    auto format(const GamePhase& phase, FormatContext& ctx) const {
        StringView name;
        switch (phase) {
            case GamePhase::Setup:
                name = "Setup"; 
                break;
            case GamePhase::PlayerTurn:
                name = "Player Turn"; 
                break;
            case GamePhase::BattlePhase:
                name = "Battle"; 
                break;
            case GamePhase::ChapterPhase:
                name = "Chapter Event"; 
                break;
            case GamePhase::EndGame:
                name = "End Game"; 
                break;
            case GamePhase::Paused:
                name = "Paused"; 
                break;
            default:
                name = "Unknown"; 
                break;
        }
        return fmt::format_to(ctx.out(), "{}", name);
    }
};

/**
 * @class Game
 * @brief Class representing the game, including state management.
 * 
 * This class unifies game logic and state management with thread-safe access
 * for UI and game threads.
 */
export class Game {
private:
    // Game board and ECS components
    SharedPtr<Board> gameBoard; ///< The game board.
    SharedPtr<Coordinator> ecsCoordinator; ///< The ECS coordinator
    Array<EntityID, GameInfo::MAX_PLAYERS> playerEntities; ///< Store player entity IDs
    
    // Game state variables
    f32 deltaTime;
    GamePhase currentPhase{GamePhase::Setup};
    u8 currentPlayerIndex{0};
    u8 chapterNumber{1};
    Array<SharedPtr<Player>, GameInfo::MAX_PLAYERS> players;
    Vector<EntityID> mobEntities;
    EntityID activeBattleAttacker{0};
    EntityID activeBattleDefender{0};
    bool battleInProgress{false};
    String statusMessage;
    
    // Systems
    SharedPtr<DamageSystem> damageSystem;
    SharedPtr<BattleSystem> battleSystem;
    SharedPtr<BattleManagerSystem> battleManagerSystem;
    
    void advanceToNextPlayer() {
        currentPlayerIndex = (currentPlayerIndex + 1) % GameInfo::MAX_PLAYERS;
        if (currentPlayerIndex == 0)
            ++chapterNumber;
    }

public:
    /**
     * @brief Constructor for the Game class.
     */
    Game():
        gameBoard{mem::make_shared<Board>(0)},
        ecsCoordinator{Coordinator::getInstance()},
        deltaTime{GlobalSettings::getInstance().getDeltaTime()} {

        ecsCoordinator->registerComponent<HealthComponent>();
        ecsCoordinator->registerComponent<StarComponent>();
        ecsCoordinator->registerComponent<PlayerComponent>();
        ecsCoordinator->registerComponent<UnitComponent>();
        ecsCoordinator->registerComponent<HandComponent>();
        ecsCoordinator->registerComponent<BattleStateComponent>();
        ecsCoordinator->registerComponent<BattleCardComponent>();
        ecsCoordinator->registerComponent<PlayerTag>();
        ecsCoordinator->registerComponent<MobTag>();

        damageSystem = ecsCoordinator->registerSystem<DamageSystem>();
        battleSystem = ecsCoordinator->registerSystem<BattleSystem>();
        battleManagerSystem = ecsCoordinator->registerSystem<BattleManagerSystem>();

        battleSystem->setDamageSystem(damageSystem);
        battleManagerSystem->setBattleSystem(battleSystem);
    }

    /**
     * @brief Initialise the game state and prepare for running
     */
    void init() {
        for (usize i = 0; i < GameInfo::MAX_PLAYERS; ++i) {
            EntityID player = ecsCoordinator->createEntity();
            ecsCoordinator->addComponent<PlayerTag>(player);
            ecsCoordinator->addComponent<PlayerComponent>(player);
            ecsCoordinator->addComponent<StarComponent>(player);
            ecsCoordinator->addComponent<HandComponent>(player);

            #ifndef NDEBUG
            playerEntities.at(i) = player;
            #else
            playerEntities[i] = player;
            #endif
        }
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Game initialised");
        #endif
    }
    
    /**
     * @brief Update game state for one frame
     */
    void update() {
        ecsCoordinator->update(deltaTime);
        
    }

    /**
     * @brief Sets the character for a player.
     * @param playerNumber The player number.
     * @param characterID The character ID.
     */
    void setPlayerCharacter(u8 playerNumber, u8 characterID) {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Setting player {} to character of ID {}\n", playerNumber, characterID);
        #endif
            
        if (playerNumber >= GameInfo::MAX_PLAYERS)
            throw OutOfRangeException("Invalid player number!");
            
        EntityID player = getPlayerEntity(playerNumber);
        SharedPtr<Character> character = CharacterFactory::getInstance().create(characterID);
        ecsCoordinator->addComponent<UnitComponent>(player, character);
        ecsCoordinator->addComponent<HealthComponent>(player, character->getHealth(), character->getHealth());
        
        SharedPtr<Player> playerWrapper = mem::make_shared<Player>(character);
        
        #ifndef NDEBUG
        players.at(playerNumber) = playerWrapper;
        #else
        players[playerNumber] = playerWrapper;
        #endif
    }

    /**
     * @brief Get the Player Entity object
     * 
     * @param playerNumber Player index
     * @return EntityID 
     */
    EntityID getPlayerEntity(u8 playerNumber) {
        if (playerNumber >= GameInfo::MAX_PLAYERS)
            throw OutOfRangeException("Invalid player number!");
        #ifndef NDEBUG
        return playerEntities.at(playerNumber);
        #else
        return playerEntities[playerNumber];
        #endif
    }

    /**
     * @brief Runs the game.
     */
    void run() {
        DebugLogger::getInstance().log("Beginning game");
            
        currentPhase = GamePhase::PlayerTurn;
    }
    
    /**
     * @brief Get current player
     * @return Current player object
     */
    SharedPtr<Player> getCurrentPlayer() const {
        #ifndef NDEBUG
        return players.at(currentPlayerIndex);
        #else
        return players[currentPlayerIndex];
        #endif
    }
    
    /**
     * @brief Get player by index
     * @param index Player index
     * @return Player object at index
     */
    SharedPtr<Player> getPlayer(u8 index) const {
        if (index >= GameInfo::MAX_PLAYERS)
            throw OutOfRangeException("Invalid index!");
        #ifndef NDEBUG
        return players.at(index);
        #else
        return players[index];
        #endif
    }
    
    /**
     * @brief Get current game phase
     * @return Current phase
     */
    GamePhase getCurrentPhase() const {
        return currentPhase;
    }
    
    /**
     * @brief Set current game phase
     * @param phase New phase
     */
    void setCurrentPhase(GamePhase phase) {
        currentPhase = phase;
    }
    
    /**
     * @brief Get chapter number
     * @return Current chapter number
     */
    u8 getChapterNumber() const {
        return chapterNumber;
    }
    
    /**
     * @brief End current player's turn
     */
    void endTurn() {
        advanceToNextPlayer();
    }
    
    /**
     * @brief Start a battle between two entities
     * @param attacker The attacking entity
     * @param defender The defending entity
     * @return True if battle started successfully
     */
    bool startBattle(EntityID attacker, EntityID defender) {
        if (battleInProgress)
            return false;
        
        activeBattleAttacker = attacker;
        activeBattleDefender = defender;
        battleInProgress = true;
        currentPhase = GamePhase::BattlePhase;
        
        return battleManagerSystem->startBattle(attacker, defender);
    }
    
    /**
     * @brief Execute the current battle
     */
    void executeBattle() {
        if (!battleInProgress)
            return;
        
        battleManagerSystem->executeBattle();
        
        endBattle();
    }
    
    /**
     * @brief End current battle
     */
    void endBattle() {
        battleInProgress = false;
        activeBattleAttacker = 0;
        activeBattleDefender = 0;
        currentPhase = GamePhase::PlayerTurn;
    }
    
    /**
     * @brief Check if battle is in progress
     * @return True if battle is ongoing
     */
    bool isBattleInProgress() const {
        return battleInProgress;
    }
    
    /**
     * @brief Get current battle attacker
     * @return Entity ID of attacker
     */
    EntityID getBattleAttacker() const {
        return activeBattleAttacker;
    }
    
    /**
     * @brief Get current battle defender
     * @return Entity ID of defender
     */
    EntityID getBattleDefender() const {
        return activeBattleDefender;
    }
    
    /**
     * @brief Set status message
     * @param message New status message
     */
    void setStatusMessage(const String& message) {
        statusMessage = message;
    }
    
    /**
     * @brief Get status message
     * @return Current status message
     */
    String getStatusMessage() const {
        return statusMessage;
    }
    
    /**
     * @brief Get game board
     * @return Reference to game board
     */
    SharedPtr<Board> getBoard() const {
        return gameBoard;
    }
    
    /**
     * @brief Add a mob entity to the game
     * @param entityId The mob's entity ID
     */
    void addMob(EntityID entityId) {
        mobEntities.push_back(entityId);
    }
    
    /**
     * @brief Get all mob entities
     * @return Vector of mob entity IDs
     */
    const Vector<EntityID>& getMobs() const {
        return mobEntities;
    }
    
    /**
     * @brief Get the ECS coordinator
     * @return Shared pointer to the coordinator
     */
    SharedPtr<Coordinator> getECS() const {
        return ecsCoordinator;
    }
    
    /**
     * @brief Convert game state to string representation
     * @return String representation of game state
     */
    String toString() const {
        String result = fmt::format(
            "Chapter: {} | Current Player: {} | Phase: {} | Battle: {}",
            chapterNumber,
            currentPlayerIndex,
            currentPhase,
            battleInProgress ? "Yes" : "No"
        );
        
        if (!statusMessage.empty())
            result = fmt::format("{} | {}", result, statusMessage);
        
        return result;
    }
};
