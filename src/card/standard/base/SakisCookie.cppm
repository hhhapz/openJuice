module;

#include <string>

export module card.standard.base.SakisCookie;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Language;
import engine.utility.Utility;

export class SakisCookie: public BoostCard {
private:
public:
    SakisCookie():
        BoostCard(Rarity::Common, 1, false, 1, 3, 0) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Saki's Cookie";
            default:
                return "Saki's Cookie";
        }
    }

    u16 getCost() const override {
        return 3;
    }
};