module;

#include <string>

export module card.standard.base.Dash;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Language;
import engine.utility.Utility;

export class Dash: public BoostCard {
private:
public:
    Dash():
        BoostCard(Rarity::Common, 1, false, 1, 3, 0) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Dash!";
            default:
                return "Dash!";
        }
    }

    u16 getCost() const override {
        return 3;
    }
};