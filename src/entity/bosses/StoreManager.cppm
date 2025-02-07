module;

#include <string>

export module entity.bosses.StoreManager;

import engine.entity.BossEnemy;

export class StoreManager: public BossEnemy {
private:

public:
    StoreManager():
        BossEnemy(103, 8, 8, 3, 2, -1) {}
};