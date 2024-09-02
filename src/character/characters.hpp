#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "characters/kai.hpp"
#include "characters/marc.hpp"
#include "characters/qp.hpp"
#include "characters/suguri.hpp"

class CharacterLibrary {
  private:
    std::map<std::string, Character*> library {

    };
  public:
    CharacterLibrary();
    ~CharacterLibrary();
    std::string getCharacterDescription(int id) const;
};