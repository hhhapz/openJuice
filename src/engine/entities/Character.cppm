module;

#include <memory>
#include <string>

export module engine.entities.Character;

import engine.utility.Utility;

export class Character {
private:
    u8 id;
    u8 health;
    u8 maxHealth;
    i8 attack;
    i8 defence;
    i8 evade;
    u8 recovery;
    std::string name;
    u16 hyperCardID;
public:
    Character(u8 id, u8 health, u8 maxHealth, i8 attack, i8 defence, i8 evade, u8 recovery, const std::string& name, u16 hyperCardID):
        id{id}, health{health}, maxHealth{maxHealth}, attack{attack}, defence{defence}, evade{evade}, recovery{recovery}, name{name}, hyperCardID{hyperCardID} {}

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

    u8 getRecovery() const {
        return recovery;
    }

    std::string getName() const {
        return name;
    }

    u16 getHyperCardID() const {
        return hyperCardID;
    }
};