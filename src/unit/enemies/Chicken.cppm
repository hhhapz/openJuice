module;

#include <string>

export module unit.enemies.Chicken;

import engine.unit.BasicEnemy;
import engine.utility.GlobalSettings;

export class Chicken: public BasicEnemy {
private:

public:
    Chicken():
        BasicEnemy(1, 3, -1, -1, 1) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Chicken";
            case Language::Japanese:
                return "ニワトリ";
            default:
                return "Chicken";
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