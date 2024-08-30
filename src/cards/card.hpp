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

class Card: public Observer {
  private:
    int id;
    int cost;
    std::string name;
    CardType type;
    bool hyper;
  public:
    Card(int cost, const std::string& name, CardType type);
    virtual ~Card() = 0;
};