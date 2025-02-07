module;

#include <memory>
#include <string>

export module card.standard.base.NiceJingle;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class NiceJingle: public BoostCard {
private:
public:
    NiceJingle():
        BoostCard(Rarity::Uncommon, 4, false, 1, 1, 0) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Nice Jingle";
            default:
                return "Nice Jingle";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Stock Effect.\nThe next bonus panel gives you twice as many stars.";
            default:
                return "Stock Effect.\nThe next bonus panel gives you twice as many stars.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"We've got a bunch.\" ―Aru";
            default:
                return "\"We've got a bunch.\" ―Aru";
        }
    }

    u16 getCost() const override {
        return 0;
    }
};