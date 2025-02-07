module;

#include <memory>
#include <string>

export module card.hyper.Accelerator;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class Accelerator: public BoostCard {
private:
public:
    Accelerator():
        BoostCard(Rarity::None, 4, true, 3, -1, -1) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Accelerator";
            default:
                return "Accelerator";
        }
    }

    std::string getDescription() const override {
        switch(GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Effect Duration: 1 chapter\nRoll two dice for movement, battle, bonus and drop.";
            default:
                return "Effect Duration: 1 chapter\nRoll two dice for movement, battle, bonus and drop.";
        }
    }

    std::string getQuote() const override {
        switch(GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"I'm accelerating.\" ―Suguri";
            default:
                return "\"I'm accelerating.\" ―Suguri";
        }
    }   

    u16 getCost() const override {
        return 30;
    }
};