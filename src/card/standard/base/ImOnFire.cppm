module;

#include <memory>
#include <string>

export module card.standard.base.ImOnFire;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class ImOnFire: public BattleCard {
private:
public:
    ImOnFire():
        BattleCard(Rarity::Common, 7, false, 1, 3, 2) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "I'm on Fire!";
            default:
                return "I'm on Fire!";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "During this battle,\ngain +1 ATK and -1 DEF.";
            default:
                return "During this battle,\ngain +1 ATK and -1 DEF.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"Let's play our lives away!\" ―Kae";
            default:
                return "\"Let's play our lives away!\" ―Kae";
        }
    }

    u16 getCost() const override {
        return 5;
    }
};