module;

#include <string>

export module engine.entity.Enemy;

import engine.entity.Entity;
import engine.utility.Utility;

export enum class EnemyType {
    BasicEncounter,
    BossEncounter
};

export class Enemy: public Entity {
private:
    const EnemyType type;
    u8 id;
public:
    Enemy(EnemyType enemyType, u8 id, u8 health, i8 attack, i8 defence, i8 evade):
        type{enemyType}, Entity(id, health, attack, defence, evade) {}

    EnemyType getType() const {
        return type;
    }
};