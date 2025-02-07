module;

#include <memory>
#include <string>

export module engine.entity.Character;

import engine.entity.Entity;
import engine.utility.Utility;

export class Character: public Entity {
private:
    u8 recovery;
    u16 hyperCardID;
public:
    Character(u8 id, u8 health, u8 maxHealth, i8 attack, i8 defence, i8 evade, u8 recovery, u16 hyperCardID):
        Entity(id, health, maxHealth, attack, defence, evade), recovery{recovery}, hyperCardID{hyperCardID} {}

    u8 getRecovery() const {
        return recovery;
    }

    u16 getHyperCardID() const {
        return hyperCardID;
    }
};