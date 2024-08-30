#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "battle.hpp"
#include "boost.hpp"
#include "event.hpp"
#include "gift.hpp"
#include "trap.hpp"
#include "../error/exceptions.hpp"

class CardLibrary {
  private:
    std::map<std::string, Card*> library {

    };
  public:
    CardLibrary();
    ~CardLibrary();
    std::string getCardDescription(int id) const;
};
