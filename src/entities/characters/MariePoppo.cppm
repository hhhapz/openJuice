module;

export module entities.characters.MariePoppo;

import engine.entities.Character;

export class MariePoppo: public Character {
private:

public:
    MariePoppo():
        Character(5, 7, 7, -1, -1, -1, 5, "MariePoppo", 5) {}
};