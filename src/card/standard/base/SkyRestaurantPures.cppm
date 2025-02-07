module;

#include <memory>
#include <string>

export module card.standard.base.SkyRestaurantPures;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class SkyRestaurantPures: public TrapCard {
private:
public:
    SkyRestaurantPures():
        TrapCard(Rarity::Rare, 15, false, 4, 1, -2) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Sky Restaurant 'Pures'";
            default:
                return "Sky Restaurant 'Pures'";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Lose half your stars and fully restore HP.";
            default:
                return "Lose half your stars and fully restore HP.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"We have a guest to treat!\" ―Chris";
            default:
                return "\"We have a guest to treat!\" ―Chris";
        }
    }

    u16 getCost() const override {
        return 0;
    }
};