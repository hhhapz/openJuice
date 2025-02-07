module;

#include <string>

export module entity.enemies.RoboBall;

import engine.entity.BasicEnemy;

export class RoboBall: public BasicEnemy {
private:

public:
    RoboBall():
        BasicEnemy(2, 3, 3, -1, 1, -1) {}
};