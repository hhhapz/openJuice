/**
 * @file CharacterFactory.cppm
 * @brief Implementation of the CharacterFactory class.
 *
 * This file contains the implementation of the CharacterFactory class, which is used to create Character objects.
 */

export module unit.CharacterFactory;

#ifdef NO_RESERVED_STD
import std.core;
import std.io;
import std.fmt;
import std.mem;
#else
import stdlib.core;
import stdlib.io;
import stdlib.fmt;
import stdlib.mem;
#endif

import engine.managers.GlobalSettings;
import engine.unit.Character;
import engine.unit.UnitFactory;
import engine.utility.EngineUtility;
import engine.utility.Exceptions;
import unit.Characters;

using stdlib::mem::SharedPtr;

using namespace exceptions;

/**
 * @class CharacterFactory
 * @brief Factory class for creating Character objects.
 * 
 * @implements UnitFactory<Character>
 * 
 * The CharacterFactory class is a singleton factory class that creates Character objects based on the given ID.
 */
export class CharacterFactory final: public UnitFactory<Character> {
private:
    /**
     * @brief Default constructor.
     */
    CharacterFactory() = default;

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    CharacterFactory(const CharacterFactory&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    CharacterFactory& operator=(const CharacterFactory&) = delete;

public:
    /**
     * @brief Get the singleton instance of the CharacterFactory.
     * @return CharacterFactory& Reference to the singleton instance of the CharacterFactory
     */
    static CharacterFactory& getInstance() {
        static CharacterFactory instance;
        return instance;
    }

    /**
     * @brief Create a Character object with the given ID.
     * @param id ID of the Character to create
     * @return SharedPtr<Character> Shared pointer to the created Character object
     * @throws InvalidIDException if an invalid ID is passed
     */
    SharedPtr<Character> create(u8 id) const override {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Creating Character of ID: {}", id);
        #endif
        
        switch (id) {
            case 1:
                return mem::make_shared<Kai>();
            case 2:
                return mem::make_shared<Marc>();
            case 3:
                return mem::make_shared<QP>();
            case 4:
                return mem::make_shared<Suguri>();
            case 5:
                return mem::make_shared<MariePoppo>();
            default:
                throw InvalidIDException(fmt::format("Unknown Character ID: {}", id));
        }
    }
};