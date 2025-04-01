/**
 * @file BossEnemyFactory.cppm
 * @brief Implementation of the BossEnemyFactory class.
 *
 * This file contains the implementation of the BossEnemyFactory class, which is used to create BossEnemy objects.
 */

export module unit.BossEnemyFactory;

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
import engine.unit.BossEnemy;
import engine.unit.UnitFactory;
import engine.utility.EngineUtility;
import engine.utility.Exceptions;
import unit.BossEnemies;

using stdlib::mem::SharedPtr;

using namespace exceptions;

/**
 * @class BossEnemyFactory
 * @brief Factory class for creating BossEnemy objects.
 * 
 * @implements UnitFactory<BossEnemy>
 * 
 * The BossEnemyFactory class is a singleton factory class that creates BossEnemy objects based on the given ID.
 */
export class BossEnemyFactory final: public UnitFactory<BossEnemy> {
private:
    /**
     * @brief Default constructor.
     */
    BossEnemyFactory() = default;

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    BossEnemyFactory(const BossEnemyFactory&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    BossEnemyFactory& operator=(const BossEnemyFactory&) = delete;

public:
    /**
     * @brief Get the singleton instance of the BossEnemyFactory.
     * @return BossEnemyFactory& Reference to the singleton instance of the BossEnemyFactory
     */
    static BossEnemyFactory& getInstance() {
        static BossEnemyFactory instance;
        return instance;
    }

    /**
     * @brief Create a BossEnemy object with the given ID.
     * @param id ID of the BossEnemy to create
     * @return SharedPtr<BossEnemy> Shared pointer to the created BossEnemy object
     * @throws InvalidIDException if an invalid ID is passed
     */
    SharedPtr<BossEnemy> create(u8 id) const override {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Creating BossEnemy of ID: {}", id);
        #endif
        
        switch (id) {
            case 1:
                return mem::make_shared<FlyingCastle>();
            case 2:
                return mem::make_shared<ShifuRobot>();
            case 3:
                return mem::make_shared<StoreManager>();
            default:
                throw InvalidIDException(fmt::format("Unknown BossEnemy ID: {}", id));
        }
    }
};