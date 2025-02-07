module;

#include <string>

export module engine.card.EventCard;

import engine.card.Card;
import engine.utilities.Utility;

export class EventCard: public Card {
private:
public:
    EventCard(u16 id, bool hyper, const std::string& name):
        Card(CardType::EventCard, id, hyper, name) {}
};