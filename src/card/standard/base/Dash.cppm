module;

#include <memory>
#include <string>

export module card.standard.base.Dash;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
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

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "For this turn, roll two dice for movement.";
            default:
                return "For this turn, roll two dice for movement.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"Faster!\" ―Suguri";
            default:
                return "\"Faster!\" ―Suguri";
        }
    }

    u16 getCost() const override {
        return 3;
    }
};