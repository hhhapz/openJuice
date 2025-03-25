/**
 * @file BossEnemy.cppm
 * @brief Definition of the BossEnemy interface.
 *
 * This file contains the definition of the BossEnemy interface, which represents a boss enemy unit.
 */

export module engine.unit.BossEnemy;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.unit.Enemy;

/**
 * @interface BossEnemy
 * @brief Interface representing a boss enemy unit.
 *
 * @extends Enemy
 * 
 * The BossEnemy interface extends the Enemy interface and represents a boss enemy unit with specific attributes.
 */
export class BossEnemy: public Enemy {
public:
    /**
     * @brief Constructor to initialise a BossEnemy object.
     * @param id The ID of the boss enemy.
     * @param health The health of the boss enemy.
     * @param attack The attack value of the boss enemy.
     * @param defence The defence value of the boss enemy.
     * @param evade The evade value of the boss enemy.
     */
    BossEnemy(u16 id, u8 health, i8 attack, i8 defence, i8 evade):
        Enemy(EnemyType::BossEncounter, id, health, attack, defence, evade) {}
};
