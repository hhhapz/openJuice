module;

#include <string>

export module engine.card.GiftCard;

import engine.card.Card;
import engine.utilities.Utility;

export class GiftCard: public Card {
private:
public:
    GiftCard(u16 id, bool hyper, const std::string& name):
        Card(CardType::GiftCard, id, hyper, name) {}
};