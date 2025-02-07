module;

export module entities.bosses.StoreManager;

import engine.entities.BossEnemy;

export class StoreManager: public BossEnemy {
private:

public:
    StoreManager():
        BossEnemy(103, 8, 8, 3, 2, -1, "Store Manager") {}
};