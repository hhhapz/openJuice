module;

export module entities.bosses.FlyingCastle;

import engine.entities.BossEnemy;

export class FlyingCastle: public BossEnemy {
private:

public:
    FlyingCastle():
        BossEnemy(101, 10, 10, 2, 1, -3, "Flying Castle") {}
};