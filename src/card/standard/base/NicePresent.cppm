module;

#include <memory>
#include <string>

export module card.standard.base.NicePresent;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class NicePresent: public BoostCard {
private:
public:
    NicePresent():
        BoostCard(Rarity::Uncommon, 5, false, 3, 1, 0) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Nice Present";
            default:
                return "Nice Present";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Draw 2 cards.";
            default:
                return "Draw 2 cards.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"You're going to help me deliver the presents.\" ―Aru";
            default:
                return "\"You're going to help me deliver the presents.\" ―Aru";
        }
    }

    u16 getCost() const override {
        return 10;
    }
};