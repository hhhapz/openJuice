/**
 * @file Components.cppm
 * @brief Module of ECS components.
 *
 * This file contains the definitions for all ECS components.
 */

export module engine.game.ecs.Components;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.mem;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.mem;
#endif

import engine.card.Card;
import engine.game.EntityComponentSystem;
import engine.unit.Unit;

using namespace collections;
using mem::SharedPtr;

/**
 * @namespace ecs::components
 * @brief Namespace of Components for the ECS system.
 */
export namespace ecs::components {
    /**
     * @enum DefenceChoice
     * @brief Enumeration for defence choices
     */
    enum class DefenceChoice {
        Defend, ///< Defend choice
        Evade ///< Evade choice
    };

    /**
     * @struct HealthComponent
     * @brief Component for Health system
     *
     * @implements Component
     */
    struct HealthComponent: public Component {
        u8 currentHealth;
        u8 maxHealth;

        /**
         * @brief Construct a new Health Component object
         * 
         * @param currentHealth 
         * @param maxHealth 
         */
        HealthComponent(u8 currentHealth, u8 maxHealth):
            currentHealth{currentHealth}, maxHealth{maxHealth} {}
    };

    /**
     * @struct StarComponent
     * @brief Component for Stars system
     *
     * @implements Component
     */
    struct StarComponent: public Component {
        u16 stars;

        /**
         * @brief Construct a new Star Component object
         * 
         * @param initialStars 
         */
        StarComponent(u16 initialStars = 0):
            stars{initialStars} {}
    };

    /**
     * @struct PlayerComponent
     * @brief Component for Player system
     *
     * @implements Component
     */
    struct PlayerComponent: public Component {
        u8 wins;
        u8 norma;

        /**
         * @brief Construct a new Player Component object
         * 
         * @param initialWins 
         * @param initialNorma 
         */
        PlayerComponent(u8 initialWins = 0, u8 initialNorma = 1):
            wins{initialWins}, norma{initialNorma} {}
    };

    /**
     * @struct UnitComponent
     * @brief Component for Unit system
     *
     * @implements Component
     */
    struct UnitComponent: public Component {
        SharedPtr<Unit> unit;

        /**
         * @brief Construct a new Unit Component object
         * 
         * @param unitPtr 
         */
        UnitComponent(SharedPtr<Unit> unitPtr):
            unit{unitPtr} {}
    };

    /**
     * @struct BattleStateComponent
     * @brief Component for tracking battle state
     * 
     * @implements Component
     */
    struct BattleStateComponent: public Component {
        DefenceChoice defenceChoice;
        SharedPtr<Card> activeBattleCard;

        /**
         * @brief Construct a new Battle State Component object
         * 
         * @param choice 
         */
        BattleStateComponent(DefenceChoice choice = DefenceChoice::Defend):
            defenceChoice{choice}, activeBattleCard{nullptr} {}
    };

    /**
     * @struct BattleCardComponent
     * @brief Component for battle card
     *
     * @implements Component
     */
     struct BattleCardComponent: public Component {
        i8 attackModifier;
        i8 defenceModifier;
        i8 evadeModifier;
        u8 extraDice;

        /**
         * @brief Construct a new Battle Card Component object
         * 
         * @param attack 
         * @param defence 
         * @param evade 
         * @param dice 
         */
        BattleCardComponent(i8 attack = 0, i8 defence = 0, i8 evade = 0, u8 dice = 0):
            attackModifier{attack}, defenceModifier{defence}, evadeModifier{evade}, extraDice{dice} {}
    };

    /**
     * @struct HandComponent
     * @brief Component for Hand system
     *
     * @implements Component
     */
    struct HandComponent: public Component {
        Vector<SharedPtr<Card>> cards;
    };

    /**
     * @interface PlayerTag
     * @brief Tag for Player
     *
     * @extends Component
     */
    struct PlayerTag: public Component {};

    /**
     * @interface MobTag
     * @brief Tag for Mob
     *
     * @extends Component
     */
    struct MobTag: public Component {};
}