module;

#include <memory>
#include <string>

export module engine.unit.Character;

import engine.unit.Unit;
import engine.utility.Utility;

export class Character: public Unit {
private:
    const u8 recovery;
    const u16 hyperCardID;
public:
    Character(u8 id, u8 health, i8 attack, i8 defence, i8 evade, u8 recovery, u16 hyperCardID):
        Unit(id, health, attack, defence, evade), recovery{recovery}, hyperCardID{hyperCardID} {}

    u8 getRecovery() const {
        return recovery;
    }

    u16 getHyperCardID() const {
        return hyperCardID;
    }
};