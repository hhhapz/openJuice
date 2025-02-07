module;

#include <string>

export module engine.card.types.BattleCard;

import engine.card.Card;
import engine.utility.Utility;

export class BattleCard: public Card {
private:
public:
    BattleCard(Rarity rarity, u16 id, bool hyper, u8 level, i8 limit, i8 deckPoints):
        Card(CardType::BattleCard, rarity, id, hyper, level, limit, deckPoints) {}
};