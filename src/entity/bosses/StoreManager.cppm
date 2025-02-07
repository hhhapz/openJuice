module;

#include <string>

export module entity.bosses.StoreManager;

import engine.entity.BossEnemy;
import engine.utility.GlobalSettings;
import engine.utility.Language;

export class StoreManager: public BossEnemy {
private:

public:
    StoreManager():
        BossEnemy(103, 8, 3, 2, -1) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Store Manager";
            default:
                return "Store Manager";
        }
    }
};