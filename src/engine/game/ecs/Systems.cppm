/**
 * @file Systems.cppm
 * @brief Module of ECS systems.
 *
 * This file contains the definitions for all ECS systems.
 */

export module engine.game.ecs.Systems;

#ifdef NO_RESERVED_STD
import std.core;
import std.mem;
import std.sys;
#else
import stdlib.core;
import stdlib.mem;
import stdlib.sys;
#endif

import engine.card.Card;
import engine.game.Dice;
import engine.game.EntityComponentSystem;
import engine.game.ecs.Components;
import engine.utility.Exceptions;
import engine.utility.RandomNumberGenerator;

using namespace exceptions;
using mem::SharedPtr;

using namespace ecs;
using namespace ecs::components;

/**
 * @namespace ecs::systems
 * @brief Namespace of Systems for the ECS system.
 */
export namespace ecs::systems {
    /**
     * @class DamageSystem
     * @brief System for Damage
     * 
     * @implements System
     */
    class DamageSystem: public System {
    private:
        /**
         * @brief 
         * 
         * @param deadEntity 
         * @param killer 
         * @throws NullPointerException if there is an error obtaining a component
         */
        void handleDeath(EntityID deadEntity, EntityID killer) {
            SharedPtr<StarComponent> deadStars = Coordinator::getInstance()->getComponent<StarComponent>(deadEntity);
            SharedPtr<StarComponent> killerStars = Coordinator::getInstance()->getComponent<StarComponent>(killer);

            if (!deadStars)
                throw NullPointerException("Error obtaining dead unit stars component!");
            if (!killerStars)
                throw NullPointerException("Error obtaining killer stars component!");

            if (deadStars && killerStars) {
                u16 transferAmount = deadStars->stars / 2;
                killerStars->stars += transferAmount;
            }

            SharedPtr<PlayerComponent> killerPlayer = Coordinator::getInstance()->getComponent<PlayerComponent>(killer);
            if (killerPlayer)
                killerPlayer->wins += Coordinator::getInstance()->getComponent<PlayerTag>(deadEntity) ? 2 : 1;
        }
    public:
        /**
         * @brief 
         * 
         * @param target 
         * @param amount 
         * @param source 
         * @return true if amount is greater or equal to the the target health's current health, false otherwise.
         * @throws NullPointerException if there is an error obtaining a component
         */
        [[nodiscard]] bool applyDamage(EntityID target, u8 amount, EntityID source) {
            SharedPtr<HealthComponent> health = Coordinator::getInstance()->getComponent<HealthComponent>(target);
            if (!health)
                throw NullPointerException("Error obtaining health component!");

            if (amount >= health->currentHealth) {
                health->currentHealth = 0;
                handleDeath(target, source);
                return true;
            } else {
                health->currentHealth -= amount;
                return false;
            }
        }

        /**
         * @brief 
         * 
         * @param deltaTime 
         */
        void update(float deltaTime) override {
            return;
        }
    };

    /**
     * @class BattleSystem
     * @brief System for Battle
     *
     * @implements System 
     */
    class BattleSystem: public System {
    private:
        SharedPtr<DamageSystem> damageSystem;
    public:
        /**
         * @brief Construct a new Battle System object
         */
        BattleSystem() = default;

        /**
         * @brief Set the Damage System object
         * 
         * @param system 
         */
        void setDamageSystem(SharedPtr<DamageSystem> system) {
            damageSystem = system;
        }

        /**
         * @brief 
         * 
         * @param attacker 
         * @param defender 
         * @return u8 
         * @throws NullPointerException if there is an error obtaining a component
         */
        u8 calculateDamage(EntityID attacker, EntityID defender) {
            SharedPtr<UnitComponent> attackerUnit = Coordinator::getInstance()->getComponent<UnitComponent>(attacker);
            SharedPtr<UnitComponent> defenderUnit = Coordinator::getInstance()->getComponent<UnitComponent>(defender);

            if (!attackerUnit || !attackerUnit->unit)
                throw NullPointerException("Error obtaining attacker component!");
            if (!defenderUnit || !defenderUnit->unit)
                throw NullPointerException("Error obtaining defender component!");

            SharedPtr<BattleStateComponent> battleState = Coordinator::getInstance()->getComponent<BattleStateComponent>(defender);

            if (!battleState)
                throw NullPointerException("Error obtaining defender battle state component!");

            i8 attackModifier = attackerUnit->unit->getAttack();
            i8 defenceModifier = defenderUnit->unit->getDefence();
            i8 evadeModifier = defenderUnit->unit->getEvade();

            u8 attackRoll = Dice::getInstance().rollD6() + attackModifier;
            attackRoll = attackRoll < 1 ? 1 : attackRoll;

            u8 defenceRoll;

            if (battleState->defenceChoice == DefenceChoice::Defend) {
                defenceRoll = Dice::getInstance().rollD6() + defenceModifier;
                defenceRoll = defenceRoll < 1 ? 1 : defenceRoll;
                return attackRoll > defenceRoll ? attackRoll - defenceRoll : 1;
            } else {
                defenceRoll = Dice::getInstance().rollD6() + evadeModifier;
                defenceRoll = defenceRoll < 1 ? 1 : defenceRoll;
                return attackRoll >= defenceRoll ? attackRoll : 0;
            }
            sys::unreachable();
        }

        /**
         * @brief 
         * 
         * @param attacker 
         * @param defender 
         * @return true if applyDamage returns true, false otherwise
         * @throws NullPointerException if the damage system is not initialised
         */
        [[nodiscard]] bool executeBattle(EntityID attacker, EntityID defender) {
            if (!damageSystem)
                throw NullPointerException("Damage system not initialised!");
            SharedPtr<BattleStateComponent> battleState = Coordinator::getInstance()->addComponent<BattleStateComponent>(defender);
            if (!battleState)
                throw NullPointerException("Error obtaining battle state!");

            u8 damage = calculateDamage(attacker, defender);
            bool defenderDefeated = damageSystem->applyDamage(defender, damage, attacker);

            if (!defenderDefeated) {
                SharedPtr<BattleStateComponent> counterBattleState = Coordinator::getInstance()->addComponent<BattleStateComponent>(attacker);
                u8 counterDamage = calculateDamage(defender, attacker);
                bool attackerDefeated = damageSystem->applyDamage(attacker, counterDamage, defender);
            }

            Coordinator::getInstance()->removeComponent<BattleStateComponent>(defender);
            if (!defenderDefeated)
                Coordinator::getInstance()->removeComponent<BattleStateComponent>(attacker);
            return true;
        }

        /**
         * @brief 
         * 
         * @param deltaTime 
         */
        void update(float deltaTime) override {
            return;
        }
    };

    /**
     * @class BattleManagerSystem
     * @brief System for managing battle flow and user interaction
     * 
     * @implements System
     */
    class BattleManagerSystem: public System {
    private:
        SharedPtr<BattleSystem> battleSystem;

        EntityID currentAttacker = 0;
        EntityID currentDefender = 0;
        bool battleInProgress = false;
    public:
        /**
         * @brief Set the Battle System reference
         */
        void setBattleSystem(SharedPtr<BattleSystem> system) {
            battleSystem = system;
        }

        /**
         * @brief Start a battle between two entities
         * 
         * @param attacker 
         * @param defender 
         * @return true if a battle completes, false otherwise
         */
        [[nodiscard]] bool startBattle(EntityID attacker, EntityID defender) {
            if (battleInProgress)
                return false;

            currentAttacker = attacker;
            currentDefender = defender;
            battleInProgress = true;

            return true;
        }

        /**
         * @brief Set the Defence Choice object
         * 
         * @param choice 
         */
        void setDefenceChoice(DefenceChoice choice) {
            if (!battleInProgress)
                return;

            SharedPtr<BattleStateComponent> battleState = Coordinator::getInstance()->getComponent<BattleStateComponent>(currentDefender);
            if (battleState)
                battleState->defenceChoice = choice;
        }

        /**
         * @brief Play a battle card for an entity
         * 
         * @param entity 
         * @param card 
         */
        void playBattleCard(EntityID entity, SharedPtr<Card> card) {
            if (!battleInProgress)
                return;

            SharedPtr<BattleStateComponent> battleState = Coordinator::getInstance()->getComponent<BattleStateComponent>(entity);
            if (battleState) {
                battleState->activeBattleCard = card;

                card->play();
            }
        }

        /**
         * @brief Execute the current battle
         */
        void executeBattle() {
            if (!battleSystem)
                throw NullPointerException("Battle system not initialised!");
            if (!battleInProgress)
                return;
            bool battleExecuted = battleSystem->executeBattle(currentAttacker, currentDefender);
            battleInProgress = false;
        }

        /**
         * @brief 
         * 
         * @param deltaTime 
         */
        void update(float deltaTime) override {
            return;
        }
    };
}