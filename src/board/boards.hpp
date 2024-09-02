#pragma once

#include <map>
#include <memory>

#include "board.hpp"

class BoardLibrary {
  private:
    std::map<int, Board*> library {
        
    };
  public:
    BoardLibrary();
    ~BoardLibrary();
};