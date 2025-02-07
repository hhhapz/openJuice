module;

#include <memory>
#include <string>

export module card.standard.base.FlipOut;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class FlipOut: public BoostCard {
private:
public:
    FlipOut():
        BoostCard(Rarity::Common, 3, false, 1, 3, -3) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Flip Out";
            default:
                return "Flip Out";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Stock Effect\nNext time you land on a drop panel, the player(s) with the highest number of stars will lose the same number of stars as you.";
            default:
                return "Stock Effect\nNext time you land on a drop panel, the player(s) with the highest number of stars will lose the same number of stars as you.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"......!\" ―Mei";
            default:
                return "\"......!\" ―Mei";
        }
    }

    u16 getCost() const override {
        return 0;
    }
};