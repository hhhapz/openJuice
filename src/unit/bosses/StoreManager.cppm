/**
 * @file StoreManager.cppm
 * @brief Implementation of the StoreManager class.
 *
 * This file contains the implementation of the StoreManager class, which represents a boss enemy in the game.
 */

export module unit.bosses.StoreManager;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.managers.TextManager;
import engine.unit.BossEnemy;

/**
 * @class StoreManager
 * @brief Class representing the StoreManager boss enemy.
 *
 * @extends BossEnemy
 *
 * The StoreManager class is a final class that inherits from BossEnemy and represents a specific type of boss enemy in the game.
 * Stats:
 * - ID: 3
 * - Health: 8
 * - Attack: 3
 * - Defence: 2
 * - Evade: -1
 */
export class StoreManager final: public BossEnemy {
private:
    static constexpr inline char UNIT_KEY[] = "CARD_UNIT_MANAGER"; ///< The key belonging to the card to query in TextManager
    static constexpr inline char ARTIST_KEY[] = "CARD_ARTIST_HONO"; ///< The key belonging to the name of the artist to query in TextManager
    static constexpr inline char VOICEACTOR_KEY[] = ""; ///< The key belonging to the name of the voice actor to query in TextManager

    /**
     * @brief No-operation function, should only be implemented by final classes.
     */
    void noop() const override {}
public:
    /**
     * @brief Constructor for the StoreManager class.
     */
    StoreManager():
        BossEnemy(3, 8, 3, 2, -1) {}

    /**
     * @brief Gets the name of the character.
     * @return The name of the character.
     */
    inline String getName() const override {
        return TextManager::getInstance().getUnitName(UNIT_KEY);
    }

    /**
     * @brief Get the description of the unit.
     * @return The description of the unit.
     */
    inline String getDescription() const override {
        return TextManager::getInstance().getUnitDescription(UNIT_KEY);
    }

    /**
     * @brief Get the unit artist name.
     * @return The unit artist name.
     */
    inline String getArtistName() const override {
        return TextManager::getInstance().getCardArtistName(ARTIST_KEY);
    }

    /**
     * @brief Get the unit voice actor name.
     * @return The unit voice actor name.
     */
    inline String getVoiceActorName() const override {
        return TextManager::getInstance().getVoiceActorName(VOICEACTOR_KEY);
    }
};
