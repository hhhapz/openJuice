module;

#include <string>

export module engine.entities.BossEnemy;

export import engine.entities.Enemy;
import engine.utility.Utility;

export class BossEnemy: public Enemy {
private:

public:
    BossEnemy(u8 id, u8 health, u8 maxHealth, i8 attack, i8 defence, i8 evade, const std::string& name):
        Enemy(EnemyType::BossEncounter, id, health, maxHealth, attack, defence, evade, name) {}
};
