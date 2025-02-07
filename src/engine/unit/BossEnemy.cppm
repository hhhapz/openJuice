module;

#include <string>

export module engine.unit.BossEnemy;

export import engine.unit.Enemy;
import engine.utility.Utility;

export class BossEnemy: public Enemy {
private:

public:
    BossEnemy(u8 id, u8 health, i8 attack, i8 defence, i8 evade):
        Enemy(EnemyType::BossEncounter, id, health, attack, defence, evade) {}
};
