module;

#include <string>

export module engine.card.TrapCard;

import engine.card.Card;
import engine.utilities.Utility;

export class TrapCard: public Card {
private:
public:
    TrapCard(u16 id, bool hyper, const std::string& name):
        Card(CardType::TrapCard, id, hyper, name) {}
};