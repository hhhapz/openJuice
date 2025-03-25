/**
 * @file SkyRestaurantPures.cppm
 * @brief Implementation of the SkyRestaurantPures class.
 *
 * This file contains the implementation of the SkyRestaurantPures class, which represents the card "Sky Restaurant 'Pures'" in the game.
 */

export module card.standard.base.SkyRestaurantPures;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.card.Card;
import engine.card.CardTypes;
import engine.card.SpawnTypes;
import engine.managers.TextManager;

/**
 * @class SkyRestaurantPures
 * @brief Class representing the SkyRestaurantPures card.
 * 
 * @implements TrapCard
 * @implements StandardCard
 *
 * The SkyRestaurantPures class implements both TrapCard and StandardCard to represent the card "Sky Restaurant 'Pures'" in the game.
 */
export class SkyRestaurantPures final: public TrapCard, public StandardCard {
private:
    static constexpr char CARD_KEY[] = "CARD_TRAP_PURES"; ///< The key belonging to the card to query in TextManager
    static constexpr char ARTIST_KEY[] = "CARD_ARTIST_NERIUME"; ///< The key belonging to the name of the artist to query in TextManager

    /**
     * @brief No-operation function, should only be implemented by final classes.
     */
    void noop() const override {}
public:
    /**
     * @brief Constructor to initialise a SkyRestaurantPures object.
     */
    SkyRestaurantPures():
        Card(CardType::TrapCard, SpawnType::Standard, Rarity::Rare, 15, 4, 1, -2) {}

    /**
     * @brief Get the name of the card.
     * @return The name of the card.
     */
    inline String getName() const override {
        return TextManager::getInstance().getCardName(CARD_KEY);
    }

    /**
     * @brief Get the description of the card.
     * @return The description of the card.
     */
    inline String getDescription() const override {
        return TextManager::getInstance().getCardDescription(CARD_KEY);
    }

    /**
     * @brief Get the flavour text of the card.
     * @return The flavour text of the card.
     */
    inline String getFlavour() const override {
        return TextManager::getInstance().getCardFlavour(CARD_KEY);
    }

    /**
     * @brief Get the card artist name.
     * @return The card artist name.
     */
    inline String getArtistName() const override {
        return TextManager::getInstance().getCardArtistName(ARTIST_KEY);
    }

    /**
     * @brief Get the cost of the card.
     * @return The cost of the card.
     */
    i16 getCost() const override {
        return 0;
    }

    /**
     * @brief Play the card.
     */
    void play() override {
        
    }
};