module;

#include <string>

export module unit.enemies.Seagull;

import engine.unit.BasicEnemy;
import engine.utility.GlobalSettings;

export class Seagull: public BasicEnemy {
private:

public:
    Seagull():
        BasicEnemy(3, 3, 1, -1, -1) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Seagull";
            case Language::Japanese:
                return "カモメ";
            default:
                return "Seagull";
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