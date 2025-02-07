module;

#include <string>

export module entity.characters.Marc;

import engine.entity.Character;
import engine.utility.GlobalSettings;
import engine.utility.Language;

export class Marc: public Character {
private:

public:
    Marc():
        Character(2, 4, 1, 1, -1, 5, 2) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Marc";
            default:
                return "Marc";
        }
    }
};