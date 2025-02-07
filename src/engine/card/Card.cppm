module;

#include <string>

export module engine.card.Card;

import engine.utility.Utility;

export enum class CardType {
    BattleCard,
    BoostCard,
    EventCard,
    GiftCard,
    TrapCard
};

export enum class Rarity {
    None,
    Common,
    Uncommon,
    Rare
};

export class Card {
private:
    const CardType type;
    const Rarity rarity;
    u16 id;
    bool hyper;
    u8 level;
    i8 limitPerDeck; // -1 if hyper, positive otherwise.
    i8 deckPoints; // -1 if hyper, non-negative otherwise.
public:
    Card(CardType cardType, Rarity rarity, u16 id, bool hyper, u8 level, i8 limit, i8 deckPoints):
        type{cardType}, rarity{rarity}, id{id}, hyper{hyper}, level{level}, limitPerDeck{limit}, deckPoints{deckPoints} {}

    CardType getCardType() const {
        return type;
    }

    Rarity getRarity() const {
        return rarity;
    }

    u16 getID() const {
        return id;
    }

    bool isHyper() const {
        return hyper;
    }

    u8 getLevel() const {
        return level;
    }

    i8 getLimit() const {
        return limitPerDeck;
    }

    i8 getDeckPoints() const {
        return deckPoints;
    }

    // Virtual, because of how strings are language-variant
    virtual std::string getName() const = 0;

    virtual std::string getDescription() const {
        return "";
    }

    // Virtual, because cards may not have constant costs
    virtual u16 getCost() const = 0;
};