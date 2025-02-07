module;

export module entities.characters.QP;

import engine.entities.Character;

export class QP: public Character {
private:

public:
    QP():
        Character(3, 5, 5, 0, 0, 0, 5, "QP", 3) {}
};