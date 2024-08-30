#pragma once

#include <algorithm>
#include <random>
#include <string>
#include <vector>

#include "../cards/binder.hpp"
#include "../error/exceptions.hpp"

class Game {
  private:
    std::vector<Card*> gameDeck;
  public:
    Game();
    ~Game();
    void shuffleDeck();
};