module;

#include <string>

export module engine.entity.BossEnemy;

export import engine.entity.Enemy;
import engine.utility.Utility;

export class BossEnemy: public Enemy {
private:

public:
    BossEnemy(u8 id, u8 health, u8 maxHealth, i8 attack, i8 defence, i8 evade):
        Enemy(EnemyType::BossEncounter, id, health, maxHealth, attack, defence, evade) {}
};
