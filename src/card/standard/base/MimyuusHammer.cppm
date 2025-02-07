module;

#include <memory>
#include <string>

export module card.standard.base.MimyuusHammer;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class MimyuusHammer: public TrapCard {
private:
public:
    MimyuusHammer():
        TrapCard(Rarity::Common, 12, false, 1, 3, 0) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Mimyuu's Hammer";
            default:
                return "Mimyuu's Hammer";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Deals 1 damage.";
            default:
                return "Deals 1 damage.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"Thank you for dying!\" ―Mimyuu";
            default:
                return "\"Thank you for dying!\" ―Mimyuu";
        }
    }

    u16 getCost() const override {
        return 0;
    }
};