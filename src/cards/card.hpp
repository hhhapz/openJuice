#pragma once

#include <string>

#include "../utility/observer.hpp"

enum class CardType {
    Boost,
    Battle,
    Trap,
    Event,
    Gift
};

enum class Rarity {
    Common,
    Uncommon,
    Rare
};

class Card: public Observer {
  private:
    int id;
    int cost;
    int level;
    std::string name;
    CardType type;
    Rarity rarity;
    bool hyper;
  public:
    Card(int cost, const std::string& name, CardType type);
    virtual ~Card() = 0;
    virtual void onPlay() = 0;
};