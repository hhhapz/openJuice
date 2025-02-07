module;

#include <string>

export module entity.bosses.FlyingCastle;

import engine.entity.BossEnemy;
import engine.utility.GlobalSettings;
import engine.utility.Language;

export class FlyingCastle: public BossEnemy {
private:

public:
    FlyingCastle():
        BossEnemy(101, 10, 2, 1, -3) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Flying Castle";
            default:
                return "Flying Castle";
        }
    }
};