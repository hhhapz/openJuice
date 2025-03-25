/**
 * @file Marc.cppm
 * @brief Implementation of the Marc class.
 *
 * This file contains the implementation of the Marc class, which represents a character in the game.
 */

export module unit.characters.Marc;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.managers.TextManager;
import engine.unit.Character;

/**
 * @class Marc
 * @brief Class representing the Marc character.
 *
 * @extends Character
 *
 * The Marc class is a final class that inherits from Character and represents a specific character in the game.
 * Stats:
 * - ID: 2
 * - Health: 4
 * - Attack: 1
 * - Defence: 1
 * - Evade: -1
 * - Recovery: 5
 */
export class Marc final: public Character {
private:
    static constexpr inline char UNIT_KEY[] = "CARD_UNIT_MARC"; ///< The key belonging to the card to query in TextManager
    static constexpr inline char ARTIST_KEY[] = "CARD_ARTIST_HONO"; ///< The key belonging to the name of the artist to query in TextManager
    static constexpr inline char VOICEACTOR_KEY[] = "VOICEACTOR_TAKAI_MAIKA"; ///< The key belonging to the name of the voice actor to query in TextManager

    /**
     * @brief No-operation function, should only be implemented by final classes.
     */
    void noop() const override {}
public:
    /**
     * @brief Constructor for the Marc class.
     */
    Marc():
        Character(2, 4, 1, 1, -1, 5) {}

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
