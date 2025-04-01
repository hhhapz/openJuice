/**
 * @file Mob.cppm
 * @brief Implementation of the Mob class.
 *
 * This file contains the implementation of the Mob class, which represents a mob entity in the game.
 */

export module engine.entity.Mob;

#ifdef NO_RESERVED_STD
import std.core;
import std.mem;
#else
import stdlib.core;
import stdlib.mem;
#endif

import engine.entity.Entity;
import engine.unit.Enemy;
import engine.game.EntityComponentSystem;
import engine.game.ecs.Components;

using stdlib::mem::SharedPtr;

using namespace ecs;
using namespace ecs::components;

/**
 * @class Mob
 * @brief Class representing a mob entity.
 *
 * @extends Entity
 * 
 * The Mob class extends the Entity abstract class and represents a mob entity in the game.
 */
export class Mob: public Entity {
public:
    /**
     * @brief Constructor to initialise a Mob object.
     * @param enemy The enemy associated with the mob.
     */
    Mob(SharedPtr<Enemy> enemy = nullptr): 
        Entity(enemy) {
        Coordinator::getInstance()->addComponent<MobTag>(getEntityID());
    }
};
