module;

#include <string>

export module engine.card.BattleCard;

import engine.card.Card;
import engine.utilities.Utility;

export class BattleCard: public Card {
private:
public:
    BattleCard(u16 id, bool hyper, const std::string& name):
        Card(CardType::BattleCard, id, hyper, name) {}
};