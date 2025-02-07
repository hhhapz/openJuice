module;

#include <string>

export module engine.card.types.BoostCard;

import engine.card.Card;
import engine.utility.Utility;

export class BoostCard: public Card {
private:
public:
    BoostCard(Rarity rarity, u16 id, bool hyper, u8 level, i8 limit, i8 deckPoints):
        Card(CardType::BoostCard, rarity, id, hyper, level, limit, deckPoints) {}
};