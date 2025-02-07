module;

#include <string>

export module entity.characters.Kai;

import engine.entity.Character;

export class Kai: public Character {
private:

public:
    Kai():
        Character(1, 5, 5, 1, 0, 0, 5, 1) {}
};