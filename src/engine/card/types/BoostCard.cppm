module;

#include <string>

export module engine.card.BoostCard;

import engine.card.Card;
import engine.utilities.Utility;

export class BoostCard: public Card {
private:
public:
    BoostCard(u16 id, bool hyper, const std::string& name):
        Card(CardType::BoostCard, id, hyper, name) {}
};