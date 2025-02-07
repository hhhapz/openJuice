module;

#include <string>

export module entity.enemies.RoboBall;

import engine.entity.BasicEnemy;
import engine.utility.GlobalSettings;
import engine.utility.Language;

export class RoboBall: public BasicEnemy {
private:

public:
    RoboBall():
        BasicEnemy(2, 3, -1, 1, -1) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "RoboBall";
            default:
                return "RoboBall";
        }
    }
};