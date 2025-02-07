module;

#include <string>

export module unit.bosses.StoreManager;

import engine.unit.BossEnemy;
import engine.utility.GlobalSettings;

export class StoreManager: public BossEnemy {
private:

public:
    StoreManager():
        BossEnemy(3, 8, 3, 2, -1) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Store Manager";
            case Language::Japanese:
                return "店長";
            default:
                return "Store Manager";
        }
    }

    // std::string getDescription() const override {
    //     switch(GlobalSettings::getInstance().getLanguage()) {
    //         case Language::English:
    //             return "No stars from bonus panel. Can only use Gift type cards. Takes 1 damage on card discard.";
    //         default:
    //             return "No stars from bonus panel. Can only use Gift type cards. Takes 1 damage on card discard.";
    //     }
    // }
};