/**
 * @file HyperCardFactory.cppm
 * @brief Implementation of the HyperCardFactory class.
 *
 * This file contains the implementation of the HyperCardFactory class, which is used to create HyperCard objects.
 */

export module card.HyperCardFactory;

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

import engine.card.Card;
import engine.card.CardFactory;
import engine.card.SpawnTypes;
import engine.managers.GlobalSettings;
import engine.utility.EngineUtility;
import engine.utility.Exceptions;
import card.HyperCards;

using namespace exceptions;
using mem::SharedPtr;

/**
 * @class HyperCardFactory
 * @brief Factory class for creating HyperCard objects.
 * 
 * @implements CardFactory<HyperCard>
 * 
 * The HyperCardFactory class is a singleton factory class that creates HyperCard objects based on the given ID.
 */
export class HyperCardFactory final: public CardFactory<HyperCard> {
private:
    /**
     * @brief Default constructor.
     */
    HyperCardFactory() = default;

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    HyperCardFactory(const HyperCardFactory&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    HyperCardFactory& operator=(const HyperCardFactory&) = delete;

public:
    /**
     * @brief Get the singleton instance of the HyperCardFactory.
     * @return HyperCardFactory& Reference to the singleton instance of the HyperCardFactory
     */
    static HyperCardFactory& getInstance() {
        static HyperCardFactory instance;
        return instance;
    }

    /**
     * @brief Create a HyperCard object with the given ID.
     *
     * @param id ID of the HyperCard to create
     * @return SharedPtr<HyperCard> Shared pointer to the created HyperCard object
     * @throws InvalidIDException if an invalid ID is passed
     */
    SharedPtr<HyperCard> create(u8 id) const override {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Creating HyperCard of ID: {}", id);
        #endif
        
        switch (id) {
            case 1:
                return mem::make_shared<ProtagonistsPrivilege>();
            case 2:
                return mem::make_shared<X16BigRocket>();
            case 3:
                return mem::make_shared<HyperMode>();
            case 4:
                return mem::make_shared<Accelerator>();
            case 5:
                return mem::make_shared<Ubiquitous>();
            default:
                throw InvalidIDException(fmt::format("Unknown HyperCard ID: {}", id));
        }
    }
};