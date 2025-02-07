module;

#include <memory>
#include <string>

export module card.standard.base.HolyNight;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class HolyNight: public EventCard {
private:
public:
    HolyNight():
        EventCard(Rarity::Common, 17, false, 1, 1, 5) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Holy Night";
            default:
                return "Holy Night";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Permanent Effect\nStart-of-chapter bonus stars are increased by one.";
            default:
                return "Permanent Effect\nStart-of-chapter bonus stars are increased by one.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"Aha, that's why it's a party night.\" ―Hime";
            default:
                return "\"Aha, that's why it's a party night.\" ―Hime";
        }
    }

    u16 getCost() const override {
        return 0;
    }
};