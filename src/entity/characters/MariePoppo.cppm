module;

#include <string>

export module entity.characters.MariePoppo;

import engine.entity.Character;

export class MariePoppo: public Character {
private:

public:
    MariePoppo():
        Character(5, 7, 7, -1, -1, -1, 5, 5) {}
};