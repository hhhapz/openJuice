module;

#include <string>

export module engine.entity.Entity;

import engine.utility.Utility;

export class Entity {
private:
    u8 id;
    u8 health;
    u8 maxHealth;
    i8 attack;
    i8 defence;
    i8 evade;
public:
    Entity(u8 id, u8 health, u8 maxHealth, i8 attack, i8 defence, i8 evade):
        id{id}, health{health}, maxHealth{maxHealth}, attack{attack}, defence{defence}, evade{evade} {}

    u8 getID() const {
        return id;
    }

    u8 getHealth() const {
        return health;
    }

    u8 getMaxHealth() const {
        return maxHealth;
    }

    i8 getAttack() const {
        return attack;
    }

    i8 getDefence() const {
        return defence;
    }

    i8 getEvade() const {
        return evade;
    }

    // Virtual, because of how strings are language-variant
    virtual std::string getName() const = 0;

    virtual std::string getDescription() const {
        return "";
    }
};