/**
 * @file Character.cppm
 * @brief Definition of the Character abstract class.
 *
 * This file contains the definition of the Character abstract class, which represents a character unit in the game.
 */

export module engine.unit.Character;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.unit.Unit;

/**
 * @class Character
 * @brief Abstract class representing a character unit.
 * 
 * @extends Unit
 *
 * The Character abstract class extends the Unit abstract class and represents a character unit with a specific recovery attribute.
 */
export class Character: public Unit {
private:
    const u8 recovery; ///< The recovery value of the character.
public:
    /**
     * @brief Constructor to initialise a Character object.
     * @param id The ID of the character.
     * @param health The health of the character.
     * @param attack The attack value of the character.
     * @param defence The defence value of the character.
     * @param evade The evade value of the character.
     * @param recovery The recovery value of the character.
     */
    Character(u8 id, u8 health, i8 attack, i8 defence, i8 evade, u8 recovery):
        Unit(id, health, attack, defence, evade), recovery{recovery} {}

    /**
     * @brief Get the recovery value of the character.
     * @return The recovery value of the character.
     */
    u8 getRecovery() const {
        return recovery;
    }
};