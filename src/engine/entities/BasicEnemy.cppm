module;

#include <string>

export module engine.entities.BasicEnemy;

export import engine.entities.Enemy;
import engine.utility.Utility;

export class BasicEnemy: public Enemy {
private:

public:
    BasicEnemy(u8 id, u8 health, u8 maxHealth, i8 attack, i8 defence, i8 evade, const std::string& name):
        Enemy(EnemyType::BasicEncounter, id, health, maxHealth, attack, defence, evade, name) {}
};