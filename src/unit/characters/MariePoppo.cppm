module;

#include <string>

export module unit.characters.MariePoppo;

import engine.unit.Character;
import engine.utility.GlobalSettings;

export class MariePoppo: public Character {
private:

public:
    MariePoppo():
        Character(5, 7, -1, -1, -1, 5, 5) {}

        std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Marie Poppo";
            case Language::Japanese:
                return "まりーぽっぽ";
            default:
                return "Marie Poppo";
        }
    }
};