module;

#include <string>

export module entity.characters.Marc;

import engine.entity.Character;

export class Marc: public Character {
private:

public:
    Marc():
        Character(2, 4, 4, 1, 1, -1, 5, 2) {}
};