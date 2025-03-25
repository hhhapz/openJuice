/**
 * @file StandardCardFactory.cppm
 * @brief Implementation of the StandardCardFactory class.
 *
 * This file contains the implementation of the StandardCardFactory class, which is used to create StandardCard objects.
 */

export module card.StandardCardFactory;

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
import card.StandardCards;

using namespace exceptions;
using mem::SharedPtr;

/**
 * @class StandardCardFactory
 * @brief Factory class for creating StandardCard objects.
 * 
 * @implements CardFactory<StandardCard>
 * 
 * The StandardCardFactory class is a singleton factory class that creates StandardCard objects based on the given ID.
 */
export class StandardCardFactory final: public CardFactory<StandardCard> {
private:
    /**
     * @brief Default constructor.
     */
    StandardCardFactory() = default;

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    StandardCardFactory(const StandardCardFactory&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    StandardCardFactory& operator=(const StandardCardFactory&) = delete;

public:
    /**
     * @brief Get the singleton instance of the StandardCardFactory.
     * @return StandardCardFactory& Reference to the singleton instance of the StandardCardFactory
     */
    static StandardCardFactory& getInstance() {
        static StandardCardFactory instance;
        return instance;
    }

    /**
     * @brief Create a StandardCard object with the given ID.
     *
     * @param id ID of the StandardCard to create
     * @return SharedPtr<StandardCard> Shared pointer to the created StandardCard object
     * @throws InvalidIDException if an invalid ID is passed
     */
    SharedPtr<StandardCard> create(u8 id) const override {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Creating StandardCard of ID: {}", id);
        #endif
        
        switch (id) {
            case 1:
                return mem::make_shared<Dash>();
            case 2:
                return mem::make_shared<SakisCookie>();
            case 3:
                return mem::make_shared<FlipOut>();
            case 4:
                return mem::make_shared<NiceJingle>();
            case 5:
                return mem::make_shared<NicePresent>();
            case 6:
                return mem::make_shared<Pudding>();
            case 7:
                return mem::make_shared<ImOnFire>();
            case 8:
                return mem::make_shared<Rbits>();
            case 9:
                return mem::make_shared<RainbowColoredCircle>();
            case 10:
                return mem::make_shared<FinalBattle>();
            case 11:
                return mem::make_shared<BadPudding>();
            case 12:
                return mem::make_shared<MimyuusHammer>();
            case 13:
                return mem::make_shared<DangerousPudding>();
            case 14:
                return mem::make_shared<Assault>();
            case 15:
                return mem::make_shared<SkyRestaurantPures>();
            case 16:
                return mem::make_shared<HereAndThere>();
            case 17:
                return mem::make_shared<HolyNight>();
            case 18:
                return mem::make_shared<OutOfAmmo>();
            case 19:
                return mem::make_shared<GiftExchange>();
            case 20:
                return mem::make_shared<LittleWar>();
            default:
                throw InvalidIDException(fmt::format("Unknown StandardCard ID: {}", id));
        }
    }
};