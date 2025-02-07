module;

#include <memory>
#include <string>

export module card.hyper.X16BigRocket;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class X16BigRocket: public BoostCard {
private:
public:
    X16BigRocket():
        BoostCard(Rarity::None, 2, true, 1, -1, -1) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Protagonist's Privilege";
            default:
                return "Protagonist's Privilege";
        }
    }

    std::string getDescription() const override {
        switch(GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "★Cost: Level x10\nDeal damage equal to your level to target enemy. A KO from this effect gives you 2 Wins.";
            default:
                return "★Cost: Level x10\nDeal damage equal to your level to target enemy. A KO from this effect gives you 2 Wins.";
        }
    }

    std::string getQuote() const override {
        switch(GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"Charged! Go!\" ―Marc;";
            default:
                return "\"Charged! Go!\" ―Marc;";
        }
    }   

    u16 getCost() const override {
        // Return 0, but call something later to deduct level * 10 stars from the player
        return 0;
    }
};