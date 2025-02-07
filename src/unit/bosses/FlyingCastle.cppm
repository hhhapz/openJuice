module;

#include <string>

export module unit.bosses.FlyingCastle;

import engine.unit.BossEnemy;
import engine.utility.GlobalSettings;

export class FlyingCastle: public BossEnemy {
private:

public:
    FlyingCastle():
        BossEnemy(1, 10, 2, 1, -3) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Flying Castle";
            case Language::Japanese:
                return "空飛ぶ城";
            default:
                return "Flying Castle";
        }
    }

    // std::string getDescription() const override {
    //     switch(GlobalSettings::getInstance().getLanguage()) {
    //         case Language::English:
    //             return "Immune to Battle Cards when defending.\nCannot Counterattack.";
    //         default:
    //             return "Immune to Battle Cards when defending.\nCannot Counterattack.";
    //     }
    // }
};