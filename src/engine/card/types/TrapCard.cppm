module;

#include <string>

export module engine.card.types.TrapCard;

import engine.card.Card;
import engine.utility.Utility;

export class TrapCard: public Card {
private:
public:
    TrapCard(Rarity rarity, u16 id, bool hyper, u8 level, i8 limit, i8 deckPoints):
        Card(CardType::TrapCard, rarity, id, hyper, level, limit, deckPoints) {}
};