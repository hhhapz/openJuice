module;

#include <string>

export module entity.bosses.FlyingCastle;

import engine.entity.BossEnemy;

export class FlyingCastle: public BossEnemy {
private:

public:
    FlyingCastle():
        BossEnemy(101, 10, 10, 2, 1, -3) {}
};