module;

#include <memory>
#include <vector>

export module engine.entity.Player;

import engine.card.Card;
import engine.entity.Entity;
import engine.utility.Utility;

export class Player: public Entity {
private:
    u16 stars;
    u8 wins;
    u8 level;
    std::vector<std::shared_ptr<Card>> hand;
public:
    Player():
        stars{1}, wins{0}, level{0} {}

    u16 getStars() const {
        return stars;
    }

    u8 getWins() const {
        return wins;
    }

    u8 getLevel() const {
        return level;
    }
};
