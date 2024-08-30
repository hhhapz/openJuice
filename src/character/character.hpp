#pragma once

class Character {
  private:
    int id;
    int health;
    int attack;
    int defence;
    int evade;
  public:
    virtual ~Character() = 0;
};