#pragma once

#include <algorithm>
#include <random>
#include <string>
#include <vector>

#include "../board/board.hpp"
#include "../cards/binder.hpp"
#include "../error/exceptions.hpp"

class Game {
  private:
    std::vector<Card*> gameDeck;
    Board* board;
  public:
    Game();
    ~Game();
    void shuffleDeck();
};