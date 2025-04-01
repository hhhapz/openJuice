/**
 * @file Entity.cppm
 * @brief Definition of the Entity abstract class.
 *
 * This file contains the definition of the Entity abstract class, which represents a generic entity in the game.
 */

module;

#include <cassert>

export module engine.entity.Entity;

#ifdef NO_RESERVED_STD
import std.core;
import std.mem;
#else
import stdlib.core;
import stdlib.mem;
#endif

import engine.game.EntityComponentSystem;
import engine.game.ecs.Components;
import engine.unit.Unit;

using stdlib::mem::SharedPtr;

using namespace ecs;
using namespace ecs::components;

/**
 * @class Entity
 * @brief Abstract class representing a generic entity.
 * 
 * The Entity abstract class represents a generic entity in the game with the following attributes: unit, stars, and current health.
 */
export class Entity {
private:
    EntityID entityId; ///< The ECS entity ID associated with this entity.

public:
    /**
     * @brief Constructor to initialise an Entity object.
     * @param unit The unit associated with the entity.
     */
    Entity(SharedPtr<Unit> unit = nullptr):
        entityId{Coordinator::getInstance()->createEntity()} {
        Coordinator::getInstance()->addComponent<StarComponent>(entityId, 0);
        
        if (unit) {
            Coordinator::getInstance()->addComponent<UnitComponent>(entityId, unit);
            Coordinator::getInstance()->addComponent<HealthComponent>(
                entityId, unit->getHealth(), unit->getHealth()
            );
        }
    }

    /**
     * @brief Default destructor.
     */
    virtual ~Entity() = default;
    
    /**
     * @brief Get the entity ID used by the ECS.
     * @return The EntityID value.
     */
    EntityID getEntityID() const {
        return entityId;
    }

    /**
     * @brief Get the number of stars the entity has.
     * @return The number of stars.
     */
    u16 getStars() const {
        SharedPtr<StarComponent> stars = Coordinator::getInstance()->getComponent<StarComponent>(entityId);
        return stars ? stars->stars : 0;
    }

    /**
     * @brief Set the number of stars the entity has.
     * @param amount The number of stars to set.
     */
    void setStars(u16 amount) {
        SharedPtr<StarComponent> stars = Coordinator::getInstance()->getComponent<StarComponent>(entityId);
        if (stars)
            stars->stars = amount;
        else
            Coordinator::getInstance()->addComponent<StarComponent>(entityId, amount);
    }

    /**
     * @brief Get the current health of the entity.
     * @return The current health.
     */
    u8 getCurrentHealth() const {
        SharedPtr<HealthComponent> health = Coordinator::getInstance()->getComponent<HealthComponent>(entityId);
        return health ? health->currentHealth : 0;
    }

    /**
     * @brief Set the current health of the entity.
     * @param health The current health to set.
     */
    void setCurrentHealth(u8 health) {
        SharedPtr<HealthComponent> healthComp = Coordinator::getInstance()->getComponent<HealthComponent>(entityId);
        if (healthComp) {
            healthComp->currentHealth = health;
        } else if (getUnit()) {
            Coordinator::getInstance()->addComponent<HealthComponent>(
                entityId, health, getUnit()->getHealth()
            );
        }
    }

    /**
     * @brief Get the unit associated with the entity.
     * @return The unit.
     */
    SharedPtr<Unit> getUnit() const {
        SharedPtr<UnitComponent> unitComp = Coordinator::getInstance()->getComponent<UnitComponent>(entityId);
        return unitComp ? unitComp->unit : nullptr;
    }

    /**
     * @brief Set the unit associated with the entity.
     * @param newUnit The new unit to set.
     */
    void setUnit(SharedPtr<Unit> newUnit) {
        assert(newUnit);
        
        if (newUnit) {
            SharedPtr<UnitComponent> unitComp = Coordinator::getInstance()->getComponent<UnitComponent>(entityId);
            if (unitComp)
                unitComp->unit = newUnit;
            else
                Coordinator::getInstance()->addComponent<UnitComponent>(entityId, newUnit);
            
            SharedPtr<HealthComponent> healthComp = Coordinator::getInstance()->getComponent<HealthComponent>(entityId);
            if (healthComp) {
                healthComp->maxHealth = newUnit->getHealth();
                healthComp->currentHealth = newUnit->getHealth();
            } else {
                Coordinator::getInstance()->addComponent<HealthComponent>(
                    entityId, newUnit->getHealth(), newUnit->getHealth()
                );
            }
        }
    }

    /**
     * @brief Get the attack value of the entity's unit.
     * @return The attack value, or 0 if no unit is assigned.
     */
    i8 getAttack() const {
        SharedPtr<Unit> unit = getUnit();
        return unit ? unit->getAttack() : 0;
    }

    /**
     * @brief Get the defense value of the entity's unit.
     * @return The defense value, or 0 if no unit is assigned.
     */
    i8 getDefense() const {
        SharedPtr<Unit> unit = getUnit();
        return unit ? unit->getDefence() : 0;
    }

    /**
     * @brief Get the evade value of the entity's unit.
     * @return The evade value, or 0 if no unit is assigned.
     */
    i8 getEvade() const {
        SharedPtr<Unit> unit = getUnit();
        return unit ? unit->getEvade() : 0;
    }

    /**
     * @brief Get the max health of the entity's unit.
     * @return The max health, or 0 if no unit is assigned.
     */
    u8 getMaxHealth() const {
        SharedPtr<HealthComponent> health = Coordinator::getInstance()->getComponent<HealthComponent>(entityId);
        return health ? health->maxHealth : 0;
    }
};