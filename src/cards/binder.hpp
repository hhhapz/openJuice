#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "battlecard.hpp"
#include "boostcard.hpp"
#include "eventcard.hpp"
#include "giftcard.hpp"
#include "trapcard.hpp"
#include "../error/exceptions.hpp"

class CardLibrary {
  private:
    std::map<int, Card*> library {

    };
  public:
    CardLibrary();
    ~CardLibrary();
    std::string getCardDescription(int id) const;
};
