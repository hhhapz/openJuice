module;

#include <string>

export module entity.enemies.Chicken;

import engine.entity.BasicEnemy;
import engine.utility.GlobalSettings;
import engine.utility.Language;

export class Chicken: public BasicEnemy {
private:

public:
    Chicken():
        BasicEnemy(1, 3, -1, -1, 1) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Chicken";
            default:
                return "Chicken";
        }
    }
};