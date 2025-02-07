module;

#include <string>

export module unit.characters.Kai;

import engine.unit.Character;
import engine.utility.GlobalSettings;

export class Kai: public Character {
private:

public:
    Kai():
        Character(1, 5, 1, 0, 0, 5, 1) {}
    
    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Kai";
            case Language::Japanese:
                return "カイ";
            default:
                return "Kai";
        }
    }
};