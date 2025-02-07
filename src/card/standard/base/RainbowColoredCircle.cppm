module;

#include <memory>
#include <string>

export module card.standard.base.RainbowColoredCircle;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class RainbowColoredCircle: public BattleCard {
private:
public:
    RainbowColoredCircle():
        BattleCard(Rarity::Common, 9, false, 2, 3, 0) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Rainbow-Colored Circle";
            default:
                return "Rainbow-Colored Circle";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "During this battle, gain +2 EVD and -1 DEF.";
            default:
                return "During this battle, gain +2 EVD and -1 DEF.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Like drawing a rainbow-colored circle.";
            default:
                return "Like drawing a rainbow-colored circle.";
        }
    }

    u16 getCost() const override {
        return 5;
    }
};