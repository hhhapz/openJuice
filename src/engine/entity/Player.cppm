/**
 * @file Player.cppm
 * @brief Implementation of the Player class.
 *
 * This file contains the implementation of the Player class, which represents a player entity in the game.
 */

export module engine.entity.Player;

#ifdef NO_RESERVED_STD
import std.core;
improt std.collections;
import std.mem;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.mem;
#endif

import engine.card.Card;
import engine.game.EntityComponentSystem;
import engine.game.ecs.Components;
import engine.entity.Entity;
import engine.unit.Unit;
import engine.unit.Character;

using namespace collections;
using mem::SharedPtr;

using namespace ecs;
using namespace ecs::components;

/**
 * @class Player
 * @brief Class representing a player entity.
 *
 * @extends Entity
 * 
 * The Player class extends the Entity abstract class and represents a player entity with attributes such as wins, norma, and hand.
 */
export class Player: public Entity {
public:
    /**
     * @brief Constructor to initialise a Player object.
     * @param character The character associated with the player.
     */
    Player(SharedPtr<Character> character = nullptr): 
        Entity(character) {
        Coordinator::getInstance()->addComponent<PlayerTag>(getEntityID());
        Coordinator::getInstance()->addComponent<PlayerComponent>(getEntityID());
        Coordinator::getInstance()->addComponent<HandComponent>(getEntityID());
    }
    
    /**
     * @brief Get the number of wins the player has.
     * @return The number of wins.
     */
    u8 getWins() const {
        SharedPtr<PlayerComponent> playerComp = Coordinator::getInstance()->getComponent<PlayerComponent>(getEntityID());
        return playerComp ? playerComp->wins : 0;
    }
    
    /**
     * @brief Set the number of wins the player has.
     * @param wins The number of wins to set.
     */
    void setWins(u8 wins) {
        SharedPtr<PlayerComponent> playerComp = Coordinator::getInstance()->getComponent<PlayerComponent>(getEntityID());
        if (playerComp)
            playerComp->wins = wins;
    }
    
    /**
     * @brief Get the norma level of the player.
     * @return The norma level.
     */
    u8 getNorma() const {
        SharedPtr<PlayerComponent> playerComp = Coordinator::getInstance()->getComponent<PlayerComponent>(getEntityID());
        return playerComp ? playerComp->norma : 1;
    }
    
    /**
     * @brief Set the norma level of the player.
     * @param norma The norma level to set.
     */
    void setNorma(u8 norma) {
        SharedPtr<PlayerComponent> playerComp = Coordinator::getInstance()->getComponent<PlayerComponent>(getEntityID());
        if (playerComp)
            playerComp->norma = norma;
    }
    
    /**
     * @brief Add a card to the player's hand.
     * @param card The card to add.
     */
    void addCard(SharedPtr<Card> card) {
        SharedPtr<HandComponent> hand = Coordinator::getInstance()->getComponent<HandComponent>(getEntityID());
        if (hand)
            hand->cards.push_back(card);
    }
    
    /**
     * @brief Get all cards in the player's hand.
     * @return Vector of cards in hand.
     */
    Vector<SharedPtr<Card>> getCards() const {
        SharedPtr<HandComponent> hand = Coordinator::getInstance()->getComponent<HandComponent>(getEntityID());
        return hand ? hand->cards : Vector<SharedPtr<Card>>();
    }

    /**
     * @brief Get the recovery value of the player's character.
     * @return The recovery value, or 0 if no character is assigned or it's not a Character.
     */
    u8 getRecovery() const {
        SharedPtr<Unit> unit = getUnit();
        SharedPtr<Character> character = mem::dynamic_pointer_cast<Character>(unit);
        return character ? character->getRecovery() : 0;
    }
};
