module;

#include <string>

export module entity.enemies.Chicken;

import engine.entity.BasicEnemy;

export class Chicken: public BasicEnemy {
private:

public:
    Chicken():
        BasicEnemy(1, 3, 3, -1, -1, 1) {}
};