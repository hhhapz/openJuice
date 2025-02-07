module;

#include <string>

export module engine.unit.Enemy;

import engine.unit.Unit;
import engine.utility.Utility;

export enum class EnemyType {
    BasicEncounter,
    BossEncounter
};

export class Enemy: public Unit {
private:
    const EnemyType type;
public:
    Enemy(EnemyType enemyType, u8 id, u8 health, i8 attack, i8 defence, i8 evade):
        type{enemyType}, Unit(id, health, attack, defence, evade) {}

    EnemyType getType() const {
        return type;
    }
};