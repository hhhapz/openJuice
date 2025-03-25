/**
 * @file Enemy.cppm
 * @brief Definition of the Enemy abstract class.
 *
 * This file contains the definition of the Enemy abstract class, which represents an enemy unit in the game.
 */

export module engine.unit.Enemy;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.unit.Unit;

/**
 * @enum EnemyType
 * @brief Enumeration for enemy types.
 *
 * @extends Unit
 * 
 * The EnemyType enumeration defines the types of enemies in the game.
 */
export enum class EnemyType {
    BasicEncounter, ///< Basic encounter enemy.
    BossEncounter ///< Boss encounter enemy.
};

/**
 * @class Enemy
 * @brief Abstract class representing an enemy unit.
 * 
 * @extends Unit
 *
 * The Enemy abstract class extends the Unit abstract class and represents an enemy unit with a specific type.
 */
export class Enemy: public Unit {
private:
    const EnemyType type; ///< The type of the enemy.
public:
    /**
     * @brief Constructor to initialise an Enemy object.
     * @param enemyType The type of the enemy.
     * @param id The ID of the enemy.
     * @param health The health of the enemy.
     * @param attack The attack value of the enemy.
     * @param defence The defence value of the enemy.
     * @param evade The evade value of the enemy.
     */
    Enemy(EnemyType enemyType, u8 id, u8 health, i8 attack, i8 defence, i8 evade):
        Unit(id, health, attack, defence, evade), type{enemyType} {}

    /**
     * @brief Get the type of the enemy.
     * @return The type of the enemy.
     */
    EnemyType getType() const {
        return type;
    }
};