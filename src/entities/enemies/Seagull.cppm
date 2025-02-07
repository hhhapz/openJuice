module;

export module entities.enemies.Seagull;

import engine.entities.BasicEnemy;

export class Seagull: public BasicEnemy {
private:

public:
    Seagull():
        BasicEnemy(3, 3, 3, 1, -1, -1, "Seagull") {}
};