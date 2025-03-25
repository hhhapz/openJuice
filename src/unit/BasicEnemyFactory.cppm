/**
 * @file BasicEnemyFactory.cppm
 * @brief Implementation of the BasicEnemyFactory class.
 *
 * This file contains the implementation of the BasicEnemyFactory class, which is used to create BasicEnemy objects.
 */

export module unit.BasicEnemyFactory;

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
import engine.unit.BasicEnemy;
import engine.unit.UnitFactory;
import engine.utility.EngineUtility;
import engine.utility.Exceptions;
import unit.BasicEnemies;

using namespace exceptions;
using mem::SharedPtr;

/**
 * @class BasicEnemyFactory
 * @brief Factory class for creating BasicEnemy objects.
 * 
 * @implements UnitFactory<BasicEnemy>
 * 
 * The BasicEnemyFactory class is a singleton factory class that creates BasicEnemy objects based on the given ID.
 */
export class BasicEnemyFactory final: public UnitFactory<BasicEnemy> {
private:
    /**
     * @brief Default constructor.
     */
    BasicEnemyFactory() = default;

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    BasicEnemyFactory(const BasicEnemyFactory&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    BasicEnemyFactory& operator=(const BasicEnemyFactory&) = delete;

public:
    /**
     * @brief Get the singleton instance of the BasicEnemyFactory.
     * @return BasicEnemyFactory& Reference to the singleton instance of the BasicEnemyFactory
     */
    static BasicEnemyFactory& getInstance() {
        static BasicEnemyFactory instance;
        return instance;
    }

    /**
     * @brief Create a BasicEnemy object with the given ID.
     * @param id ID of the BasicEnemy to create
     * @return SharedPtr<BasicEnemy> Shared pointer to the created BasicEnemy object
     * @throws InvalidIDException if an invalid ID is passed
     */
    SharedPtr<BasicEnemy> create(u8 id) const override {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Creating BasicEnemy of ID: {}", id);
        #endif
        
        switch (id) {
            case 1:
                return mem::make_shared<Chicken>();
            case 2:
                return mem::make_shared<RoboBall>();
            case 3:
                return mem::make_shared<Seagull>();
            default:
                throw InvalidIDException(fmt::format("Unknown BasicEnemy ID: {}", id));
        }
    }
};