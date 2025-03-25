/**
 * @file X16BigRocket.cppm
 * @brief Implementation of the X16BigRocket class.
 *
 * This file contains the implementation of the X16BigRocket class, which represents the card "x16 Big Rocket" in the game.
 */

export module card.hyper.X16BigRocket;

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
 * @class X16BigRocket
 * @brief Class representing the X16BigRocket card.
 *
 * @implements BoostCard
 * @implements HyperCard
 * 
 * The X16BigRocket class implements both BoostCard and HyperCard to represent the card "x16 Big Rocket" in the game.
 */
export class X16BigRocket final: public BoostCard, public HyperCard {
private:
    static constexpr char CARD_KEY[] = "CARD_HYPER_MARC"; ///< The key belonging to the card to query in TextManager
    static constexpr char ARTIST_KEY[] = "CARD_ARTIST_HONO"; ///< The key belonging to the name of the artist to query in TextManager

    /**
     * @brief No-operation function, should only be implemented by final classes.
     */
    void noop() const override {}
public:
    /**
     * @brief Constructor to initialise an X16BigRocket object.
     */
    X16BigRocket():
        Card(CardType::BoostCard, SpawnType::Hyper, Rarity::None, 2, 1, -1, -1) {}

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
        // Return -1, but call something later to deduct level * 10 stars from the player
        return -1;
    }

    /**
     * @brief Play the card.
     */
    void play() override {
        
    }
};