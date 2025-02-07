module;

#include <memory>
#include <string>

export module card.standard.base.FinalBattle;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class FinalBattle: public BattleCard {
private:
public:
    FinalBattle():
        BattleCard(Rarity::Rare, 10, false, 4, 1, -2) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Final Battle";
            default:
                return "Final Battle";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "This battle will last until either unit suffers KO (Maximum of 10 rounds).";
            default:
                return "This battle will last until either unit suffers KO (Maximum of 10 rounds).";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"To protect everyone!\"\n―Suguri & Hime";
            default:
                return "\"To protect everyone!\"\n―Suguri & Hime";
        }
    }

    u16 getCost() const override {
        return 30;
    }
};