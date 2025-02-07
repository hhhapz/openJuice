module;

#include <memory>
#include <string>

export module card.hyper.Ubiquitous;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class Ubiquitous: public BoostCard {
private:
public:
    Ubiquitous():
        BoostCard(Rarity::None, 5, true, 3, -1, -1) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Ubiquitous";
            default:
                return "Ubiquitous";
        }
    }

    std::string getDescription() const override {
        switch(GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Warp to target active enemy's panel. In addition, steal stars equal to 10x their level.";
            default:
                return "Warp to target active enemy's panel. In addition, steal stars equal to 10x their level.";
        }
    }

    std::string getQuote() const override {
        switch(GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"Poppo! Poppopopopopo!\"\n―Marie Poppo";
            default:
                return "\"Poppo! Poppopopopopo!\"\n―Marie Poppo";
        }
    }   

    u16 getCost() const override {
        return 0;
    }
};