module;

#include <memory>
#include <string>

export module card.standard.base.Rbits;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class Rbits: public BattleCard {
private:
public:
    Rbits():
        BattleCard(Rarity::Common, 8, false, 2, 3, 2) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Rbits";
            default:
                return "Rbits";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "During this battle, gain +2 DEF. You may not use the Evade command.";
            default:
                return "During this battle, gain +2 DEF. You may not use the Evade command.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"Formation Orbit!\" ―QP";
            default:
                return "\"Formation Orbit!\" ―QP";
        }
    }

    u16 getCost() const override {
        return 3;
    }
};