module;

#include <string>

export module unit.bosses.ShifuRobot;

import engine.unit.BossEnemy;
import engine.utility.GlobalSettings;

export class ShifuRobot: public BossEnemy {
private:

public:
    ShifuRobot():
        BossEnemy(2, 7, 2, 3, -2) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Shifu Robot";
            case Language::Japanese:
                return "シフロボ";
            default:
                return "Shifu Robot";
        }
    }

    // std::string getDescription() const override {
    //     switch(GlobalSettings::getInstance().getLanguage()) {
    //         case Language::English:
    //             return "Start and Auto-Revive with 1 HP and a 1 HP Absorptive Shell.\nAuto-Repair: At the start of your turn, every 3rd chapter, heal 1 HP and remove Absorptive Shell.\nRevive with -1 MOV for 2 chapters.";
    //         default:
    //             return "Start and Auto-Revive with 1 HP and a 1 HP Absorptive Shell.\nAuto-Repair: At the start of your turn, every 3rd chapter, heal 1 HP and remove Absorptive Shell.\nRevive with -1 MOV for 2 chapters.";
    //     }
    // }
};