module;

export module entities.characters.Marc;

import engine.entities.Character;

export class Marc: public Character {
private:

public:
    Marc():
        Character(2, 4, 4, 1, 1, -1, 5, "Marc", 2) {}
};