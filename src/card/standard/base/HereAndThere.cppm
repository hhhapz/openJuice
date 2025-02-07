module;

#include <memory>
#include <string>

export module card.standard.base.HereAndThere;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class HereAndThere: public EventCard {
private:
public:
    HereAndThere():
        EventCard(Rarity::Common, 16, false, 2, 3, 0) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Here and There";
            default:
                return "Here and There";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "All units are moved to randomly chosen panels.";
            default:
                return "All units are moved to randomly chosen panels.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"To the next world!\" ―Marie Poppo";
            default:
                return "\"To the next world!\" ―Marie Poppo";
        }
    }

    u16 getCost() const override {
        return 10;
    }
};