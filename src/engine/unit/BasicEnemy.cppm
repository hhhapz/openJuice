/**
 * @file BasicEnemy.cppm
 * @brief Definition of the BasicEnemy interface.
 *
 * This file contains the structure of the BasicEnemy interface, which represents a basic enemy unit.
 */

export module engine.unit.BasicEnemy;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.unit.Enemy;

/**
 * @interface BasicEnemy
 * @brief Interface representing a basic enemy unit.
 *
 * @extends Enemy
 * 
 * The BasicEnemy interface extends the Enemy interface and represents a basic enemy unit with specific attributes.
 */
export class BasicEnemy: public Enemy {
public:
    /**
     * @brief Constructor to initialise a BasicEnemy object.
     * @param id The ID of the enemy.
     * @param health The health of the enemy.
     * @param attack The attack value of the enemy.
     * @param defence The defence value of the enemy.
     * @param evade The evade value of the enemy.
     */
    BasicEnemy(u8 id, u8 health, i8 attack, i8 defence, i8 evade):
        Enemy(EnemyType::BasicEncounter, id, health, attack, defence, evade) {}
};