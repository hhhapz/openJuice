module;

#include <string>

export module unit.characters.QP;

import engine.unit.Character;
import engine.utility.GlobalSettings;

export class QP: public Character {
private:

public:
    QP():
        Character(3, 5, 0, 0, 0, 5, 3) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "QP";
            case Language::Japanese:
                return "きゅーぴー";
            default:
                return "QP";
        }
    }
};