module;

#include <string>

export module entity.enemies.Seagull;

import engine.entity.BasicEnemy;
import engine.utility.GlobalSettings;
import engine.utility.Language;

export class Seagull: public BasicEnemy {
private:

public:
    Seagull():
        BasicEnemy(3, 3, 1, -1, -1) {}

        std::string getName() const override {
            switch (GlobalSettings::getInstance().getLanguage()) {
                case Language::English:
                    return "Seagull";
                default:
                    return "Seagull";
            }
        }
};