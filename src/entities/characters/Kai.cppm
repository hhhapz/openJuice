module;

export module entities.characters.Kai;

import engine.entities.Character;

export class Kai: public Character {
private:

public:
    Kai():
        Character(1, 5, 5, 1, 0, 0, 5, "Kai", 1) {}
};