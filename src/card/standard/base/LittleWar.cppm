module;

#include <memory>
#include <string>

export module card.standard.base.LittleWar;

import engine.card.Card;
import engine.card.CardTypes;
import engine.utility.GlobalSettings;
import engine.utility.Utility;

export class LittleWar: public EventCard {
private:
public:
    LittleWar():
        EventCard(Rarity::Rare, 20, false, 4, 1, 2) {}

    std::string getName() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Little War";
            default:
                return "Little War";
        }
    }

    std::string getDescription() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "Effect Duration: 3 chapters\nOffense and defense will happen twice in all battles.";
            default:
                return "Effect Duration: 3 chapters\nOffense and defense will happen twice in all battles.";
        }
    }

    std::string getQuote() const override {
        switch (GlobalSettings::getInstance().getLanguage()) {
            case Language::English:
                return "\"I believe... I have the power to stop this...\" ―Suguri";
            default:
                return "\"I believe... I have the power to stop this...\" ―Suguri";
        }
    }

    u16 getCost() const override {
        return 50;
    }
};