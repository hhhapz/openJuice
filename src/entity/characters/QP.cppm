module;

#include <string>

export module entity.characters.QP;

import engine.entity.Character;

export class QP: public Character {
private:

public:
    QP():
        Character(3, 5, 5, 0, 0, 0, 5, 3) {}
};