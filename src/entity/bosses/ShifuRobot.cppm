module;

#include <string>

export module entity.bosses.ShifuRobot;

import engine.entity.BossEnemy;

export class ShifuRobot: public BossEnemy {
private:

public:
    ShifuRobot():
        BossEnemy(102, 7, 7, 2, 3, -2) {}
};