module;

#include <string>

export module unit.characters.Suguri;

import engine.unit.Character;
import engine.utility.GlobalSettings;

export class Suguri: public Character {
private:

public:
    Suguri():
        Character(4, 4, 1, -1, 2, 5, 4) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Suguri";
            case Language::Japanese:
                return "スグリ";
            default:
                return "Suguri";
        }
    }
};