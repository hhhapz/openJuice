module;

#include <string>

export module entity.characters.Suguri;

import engine.entity.Character;

export class Suguri: public Character {
private:

public:
    Suguri():
        Character(4, 4, 4, 1, -1, 2, 5, 4) {}
};