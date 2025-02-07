module;

#include <string>

export module card.hyper.ProtagonistsPrivilege;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Language;
import engine.utility.Utility;

export class ProtagonistsPrivilege: public BoostCard {
private:
public:
    ProtagonistsPrivilege():
        BoostCard(Rarity::None, 1, true, 3, -1, -1) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Protagonist's Privilege";
            default:
                return "Protagonist's Privilege";
        }
    }

    u16 getCost() const override {
        return 20;
    }
};