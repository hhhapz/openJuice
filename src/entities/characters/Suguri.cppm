module;

export module entities.characters.Suguri;

import engine.entities.Character;

export class Suguri: public Character {
private:

public:
    Suguri():
        Character(4, 4, 4, 1, -1, 2, 5, "Suguri", 4) {}
};