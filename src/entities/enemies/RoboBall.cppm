module;

export module entities.enemies.RoboBall;

import engine.entities.BasicEnemy;

export class RoboBall: public BasicEnemy {
private:

public:
    RoboBall():
        BasicEnemy(2, 3, 3, -1, 1, -1, "RoboBall") {}
};