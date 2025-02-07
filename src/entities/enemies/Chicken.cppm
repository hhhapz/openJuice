module;

export module entities.enemies.Chicken;

import engine.entities.BasicEnemy;

export class Chicken: public BasicEnemy {
private:

public:
    Chicken():
        BasicEnemy(1, 3, 3, -1, -1, 1, "Chicken") {}
};