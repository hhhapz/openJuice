/**
 * @file RoboBall.cppm
 * @brief Implementation of the RoboBall class.
 *
 * This file contains the implementation of the RoboBall class, which represents a basic enemy in the game.
 */

export module unit.enemies.RoboBall;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.managers.TextManager;
import engine.unit.BasicEnemy;

/**
 * @class RoboBall
 * @brief Class representing the RoboBall enemy.
 *
 * @extends BasicEnemy
 *
 * The RoboBall class is a final class that inherits from BasicEnemy and represents a specific type of enemy in the game.
 * Stats:
 * - ID: 2
 * - Health: 3
 * - Attack: -1
 * - Defence: 1
 * - Evade: -1
 */
export class RoboBall final: public BasicEnemy {
private:
    static constexpr inline char UNIT_KEY[] = "CARD_UNIT_ROBOBALL"; ///< The key belonging to the card to query in TextManager
    static constexpr inline char ARTIST_KEY[] = "CARD_ARTIST_HONO"; ///< The key belonging to the name of the artist to query in TextManager
    static constexpr inline char VOICEACTOR_KEY[] = ""; ///< The key belonging to the name of the voice actor to query in TextManager

    /**
     * @brief No-operation function, should only be implemented by final classes.
     */
    void noop() const override {}
public:
    /**
     * @brief Constructor for the RoboBall class.
     */
    RoboBall():
        BasicEnemy(2, 3, -1, 1, -1) {}

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
