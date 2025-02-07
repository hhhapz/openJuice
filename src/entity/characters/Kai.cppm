module;

#include <string>

export module entity.characters.Kai;

import engine.entity.Character;
import engine.utility.GlobalSettings;
import engine.utility.Language;

export class Kai: public Character {
private:

public:
    Kai():
        Character(1, 5, 1, 0, 0, 5, 1) {}
    
    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Kai";
            default:
                return "Kai";
        }
    }
};