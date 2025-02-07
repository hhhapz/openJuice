module;

#include <string>

export module entity.enemies.Seagull;

import engine.entity.BasicEnemy;

export class Seagull: public BasicEnemy {
private:

public:
    Seagull():
        BasicEnemy(3, 3, 3, 1, -1, -1) {}
};