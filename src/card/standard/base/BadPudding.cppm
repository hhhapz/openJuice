module;

#include <memory>
#include <string>

export module card.standard.base.BadPudding;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class BadPudding: public TrapCard {
private:
public:
    BadPudding():
        TrapCard(Rarity::Common, 11, false, 1, 3, -2) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Bad Pudding";
            default:
                return "Bad Pudding";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Discard a random card.";
            default:
                return "Discard a random card.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"Pudding with soy sauce, tastes like sea urchin!\" ―Yuki";
            default:
                return "\"Pudding with soy sauce, tastes like sea urchin!\" ―Yuki";
        }
    }

    u16 getCost() const override {
        return 0;
    }
};