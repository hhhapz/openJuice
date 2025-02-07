module;

#include <string>

export module entity.characters.MariePoppo;

import engine.entity.Character;
import engine.utility.GlobalSettings;
import engine.utility.Language;

export class MariePoppo: public Character {
private:

public:
    MariePoppo():
        Character(5, 7, -1, -1, -1, 5, 5) {}

        std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Marie Poppo";
            default:
                return "Marie Poppo";
        }
    }
};