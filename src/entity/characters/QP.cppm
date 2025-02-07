module;

#include <string>

export module entity.characters.QP;

import engine.entity.Character;
import engine.utility.GlobalSettings;
import engine.utility.Language;

export class QP: public Character {
private:

public:
    QP():
        Character(3, 5, 0, 0, 0, 5, 3) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "QP";
            default:
                return "QP";
        }
    }
};