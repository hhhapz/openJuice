module;

#include <string>

export module engine.card.types.GiftCard;

import engine.card.Card;
import engine.utility.Utility;

export class GiftCard: public Card {
private:
public:
    GiftCard(Rarity rarity, u16 id, bool hyper, u8 level, i8 limit, i8 deckPoints):
        Card(CardType::GiftCard, rarity, id, hyper, level, limit, deckPoints) {}
};