module;

#include <string>

export module engine.entity.BasicEnemy;

export import engine.entity.Enemy;
import engine.utility.Utility;

export class BasicEnemy: public Enemy {
private:

public:
    BasicEnemy(u8 id, u8 health, i8 attack, i8 defence, i8 evade):
        Enemy(EnemyType::BasicEncounter, id, health, attack, defence, evade) {}
};