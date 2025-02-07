module;

#include <memory>
#include <string>

export module card.standard.base.Assault;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class Assault: public TrapCard {
private:
public:
    Assault():
        TrapCard(Rarity::Uncommon, 14, false, 2, 3, -2) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Assault";
            default:
                return "Assault";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Battle the player who set this card, starting with their attack.";
            default:
                return "Battle the player who set this card, starting with their attack.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"I'll make you leave the guild today for sure!\" ―Peat";
            default:
                return "\"I'll make you leave the guild today for sure!\" ―Peat";
        }
    }

    u16 getCost() const override {
        return 0;
    }
};