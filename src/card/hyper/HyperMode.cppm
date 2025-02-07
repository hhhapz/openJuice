module;

#include <memory>
#include <string>

export module card.hyper.HyperMode;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class HyperMode: public BattleCard {
private:
public:
    HyperMode():
        BattleCard(Rarity::None, 3, true, 1, -1, -1) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Hyper Mode";
            default:
                return "Hyper Mode";
        }
    }

    std::string getDescription() const override {
        switch(GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Gain +2 ATK during this battle. If your unit suffers KO during this battle, you give no stars or Wins and the unit will revive next turn.";
            default:
                return "Gain +2 ATK during this battle. If your unit suffers KO during this battle, you give no stars or Wins and the unit will revive next turn.";
        }
    }

    std::string getQuote() const override {
        switch(GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"HYPER MODE!\" ―QP";
            default:
                return "\"HYPER MODE!\" ―QP";
        }
    }   

    u16 getCost() const override {
        return 10;
    }
};