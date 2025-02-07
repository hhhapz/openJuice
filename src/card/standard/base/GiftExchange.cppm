module;

#include <memory>
#include <string>

export module card.standard.base.GiftExchange;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class GiftExchange: public EventCard {
private:
public:
    GiftExchange():
        EventCard(Rarity::Uncommon, 19, false, 3, 3, 0) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Gift Exchange";
            default:
                return "Gift Exchange";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "All cards are gathered from the players and dealt back randomly. The total number of each player's cards remains unchanged.";
            default:
                return "All cards are gathered from the players and dealt back randomly. The total number of each player's cards remains unchanged.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"A gift exchange? Let's do it!\"\n―Rbit, Red and Blue";
            default:
                return "\"A gift exchange? Let's do it!\"\n―Rbit, Red and Blue";
        }
    }

    u16 getCost() const override {
        return 10;
    }
};