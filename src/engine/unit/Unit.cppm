module;

#include <string>

export module engine.unit.Unit;

import engine.utility.Utility;

export class Unit {
private:
    const u8 id;
    const u8 health;
    const i8 attack;
    const i8 defence;
    const i8 evade;
public:
    Unit(u8 id, u8 health, i8 attack, i8 defence, i8 evade):
        id{id}, health{health}, attack{attack}, defence{defence}, evade{evade} {}

    u8 getID() const {
        return id;
    }

    u8 getHealth() const {
        return health;
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