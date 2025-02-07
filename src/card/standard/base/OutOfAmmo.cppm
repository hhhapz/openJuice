module;

#include <memory>
#include <string>

export module card.standard.base.OutOfAmmo;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class OutOfAmmo: public EventCard {
private:
public:
    OutOfAmmo():
        EventCard(Rarity::Uncommon, 18, false, 2, 3, -2) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Out of Ammo";
            default:
                return "Out of Ammo";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Effect Duration: 1 chapter\nNo player may use any cards.";
            default:
                return "Effect Duration: 1 chapter\nNo player may use any cards.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"Ran out of ammo!\" ―Peat";
            default:
                return "\"Ran out of ammo!\" ―Peat";
        }
    }

    u16 getCost() const override {
        return 5;
    }
};