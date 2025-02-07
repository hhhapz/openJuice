module;

#include <string>

export module engine.card.Card;

import engine.utilities.Utility;

export enum class CardType {
    BattleCard,
    BoostCard,
    EventCard,
    GiftCard,
    TrapCard
};

export class Card {
private:
    const CardType type;
    u16 id;
    bool hyper;
    std::string name;
public:
    Card(CardType cardType, u16 id, bool hyper, const std::string& name):
        type{cardType}, id{id}, hyper{hyper}, name{name} {}

    CardType getCardType() const {
        return type;
    }

    u16 getID() const {
        return id;
    }

    bool isHyper() const {
        return hyper;
    }

    std::string getName() const {
        return name;
    }
};