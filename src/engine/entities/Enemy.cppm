module;

#include <string>

export module engine.entities.Enemy;

import engine.utility.Utility;

export enum class EnemyType {
    BasicEncounter,
    BossEncounter
};

export class Enemy {
private:
    const EnemyType type;
    u8 id;
    u8 health;
    u8 maxHealth;
    i8 attack;
    i8 defence;
    i8 evade;
    std::string name;
public:
    Enemy(EnemyType enemyType, u8 id, u8 health, u8 maxHealth, i8 attack, i8 defence, i8 evade, const std::string& name):
        type{enemyType}, id{id}, health{health}, maxHealth{maxHealth}, attack{attack}, defence{defence}, evade{evade}, name{name} {}

    EnemyType getType() const {
        return type;
    }

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

    std::string getName() const {
        return name;
    }
};