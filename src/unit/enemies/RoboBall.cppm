module;

#include <string>

export module unit.enemies.RoboBall;

import engine.unit.BasicEnemy;
import engine.utility.GlobalSettings;

export class RoboBall: public BasicEnemy {
private:

public:
    RoboBall():
        BasicEnemy(2, 3, -1, 1, -1) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "RoboBall";
            case Language::Japanese:
                return "ロボボール";
            default:
                return "RoboBall";
        }
    }

    // std::string getDescription() const override {
    //     switch(GlobalSettings::getInstance().getLanguage()) {
    //         case Language::English:
    //             return "Lose 1/4 stars and give 1 in when KO'd in battle.";
    //         default:
    //             return "Lose 1/4 stars and give 1 in when KO'd in battle.";
    //     }
    // }
};