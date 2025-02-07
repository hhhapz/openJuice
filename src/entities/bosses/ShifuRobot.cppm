module;

export module entities.bosses.ShifuRobot;

import engine.entities.BossEnemy;

export class ShifuRobot: public BossEnemy {
private:

public:
    ShifuRobot():
        BossEnemy(102, 7, 7, 2, 3, -2, "Shifu Robot") {}
};