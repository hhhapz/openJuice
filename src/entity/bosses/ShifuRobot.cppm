module;

#include <string>

export module entity.bosses.ShifuRobot;

import engine.entity.BossEnemy;
import engine.utility.GlobalSettings;
import engine.utility.Language;

export class ShifuRobot: public BossEnemy {
private:

public:
    ShifuRobot():
        BossEnemy(102, 7, 2, 3, -2) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Shifu Robot";
            default:
                return "Shifu Robot";
        }
    }
};