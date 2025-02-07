module;

#include <memory>
#include <string>

export module card.standard.base.Pudding;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class Pudding: public BoostCard {
private:
public:
    Pudding():
        BoostCard(Rarity::Rare, 6, false, 4, 3, 5) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Pudding";
            default:
                return "Pudding";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Fully restore HP.";
            default:
                return "Fully restore HP.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"Hooray!\" ―QP";
            default:
                return "\"Hooray!\" ―QP";
        }
    }

    u16 getCost() const override {
        return 0;
    }
};