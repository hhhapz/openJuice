module;

#include <string>

export module engine.card.types.EventCard;

import engine.card.Card;
import engine.utility.Utility;

export class EventCard: public Card {
private:
public:
    EventCard(Rarity rarity, u16 id, bool hyper, u8 level, i8 limit, i8 deckPoints):
        Card(CardType::EventCard, rarity, id, hyper, level, limit, deckPoints) {}
};