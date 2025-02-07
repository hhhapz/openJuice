module;

#include <string>

export module unit.characters.Marc;

import engine.unit.Character;
import engine.utility.GlobalSettings;

export class Marc: public Character {
private:

public:
    Marc():
        Character(2, 4, 1, 1, -1, 5, 2) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Marc";
            case Language::Japanese:
                return "マール";
            default:
                return "Marc";
        }
    }
};