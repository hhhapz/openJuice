/**
 * @file Unit.cppm
 * @brief Definition of the Unit abstract class.
 *
 * This file contains the definition of the Unit abstract class, which represents a generic unit in the game.
 */

export module engine.unit.Unit;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.utility.Interfaces;

/**
 * @class Unit
 * @brief Abstract class representing a generic unit.
 * 
 * The Unit abstract class represents a generic unit in the game with the following attributes: ID, health, attack, defence, and evade.
 *
 * @implements FinalOnly
 * @implements KeyQueryable
 */
export class Unit: public FinalOnly, public KeyQueryable {
private:
    const u8 id; ///< The ID of the unit.
    const u8 health; ///< The health of the unit.
    const i8 attack; ///< The attack value of the unit.
    const i8 defence; ///< The defence value of the unit.
    const i8 evade; ///< The evade value of the unit.
public:
    /**
     * @brief Constructor to initialise a Unit object.
     * @param id The ID of the unit.
     * @param health The health of the unit.
     * @param attack The attack value of the unit.
     * @param defence The defence value of the unit.
     * @param evade The evade value of the unit.
     */
    Unit(u8 id, u8 health, i8 attack, i8 defence, i8 evade):
        id{id}, health{health}, attack{attack}, defence{defence}, evade{evade} {}

    /**
     * @brief Get the ID of the unit.
     * @return The ID of the unit.
     */
    u8 getID() const {
        return id;
    }

    /**
     * @brief Get the health of the unit.
     * @return The health of the unit.
     */
    u8 getHealth() const {
        return health;
    }

    /**
     * @brief Get the attack value of the unit.
     * @return The attack value of the unit.
     */
    i8 getAttack() const {
        return attack;
    }

    /**
     * @brief Get the defence value of the unit.
     * @return The defence value of the unit.
     */
    i8 getDefence() const {
        return defence;
    }

    /**
     * @brief Get the evade value of the unit.
     * @return The evade value of the unit.
     */
    i8 getEvade() const {
        return evade;
    }

    /**
     * @brief Get the name of the unit.
     * @return The name of the unit.
     */
    inline virtual String getName() const {
        return "";
    }

    /**
     * @brief Get the description of the unit.
     * @return The description of the unit.
     */
    inline virtual String getDescription() const {
        return "";
    }

    /**
     * @brief Get the unit artist name.
     * @return The unit artist name.
     */
    inline virtual String getArtistName() const {
        return "";
    }

    /**
     * @brief Get the unit voice actor name.
     * @return The unit voice actor name.
     */
    inline virtual String getVoiceActorName() const {
        return "";
    }
};