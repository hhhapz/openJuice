module;

#include <memory>
#include <string>

export module card.standard.base.DangerousPudding;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class DangerousPudding: public TrapCard {
private:
public:
    DangerousPudding():
        TrapCard(Rarity::Common, 13, false, 1, 3, 0) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Dangerous Pudding";
            default:
                return "Dangerous Pudding";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Stock Effect\nYour next turn will be skipped.";
            default:
                return "Stock Effect\nYour next turn will be skipped.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "'One glance is all it took for that pudding to steal my heart.'";
            default:
                return "'One glance is all it took for that pudding to steal my heart.'";
        }
    }

    u16 getCost() const override {
        return 0;
    }
};