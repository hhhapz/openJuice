#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "characters/kai.hpp"

class CharacterLibrary {
  private:
    std::map<std::string, Character*> library {

    };
  public:
    CharacterLibrary();
    ~CharacterLibrary();
    std::string getCharacterDescription(int id) const;
};