module;

#include <string>

export module entity.characters.Suguri;

import engine.entity.Character;
import engine.utility.GlobalSettings;
import engine.utility.Language;

export class Suguri: public Character {
private:

public:
    Suguri():
        Character(4, 4, 1, -1, 2, 5, 4) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Suguri";
            default:
                return "Suguri";
        }
    }
};