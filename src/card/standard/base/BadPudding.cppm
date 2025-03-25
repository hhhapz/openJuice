/**
 * @file BadPudding.cppm
 * @brief Implementation of the BadPudding class.
 *
 * This file contains the implementation of the BadPudding class, which represents the card "Bad Pudding" in the game.
 */

export module card.standard.base.BadPudding;

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
 * @class BadPudding
 * @brief Class representing the BadPudding card.
 * 
 * @implements TrapCard
 * @implements StandardCard
 *
 * The BadPudding class implements both TrapCard and StandardCard to represent the card "Bad Pudding" in the game.
 */
export class BadPudding final: public TrapCard, public StandardCard {
private:
    static constexpr char CARD_KEY[] = "CARD_TRAP_BADPUDDING"; ///< The key belonging to the card to query in TextManager
    static constexpr char ARTIST_KEY[] = "CARD_ARTIST_HONO"; ///< The key belonging to the name of the artist to query in TextManager

    /**
     * @brief No-operation function, should only be implemented by final classes.
     */
    void noop() const override {}
public:
    /**
     * @brief Constructor to initialise a BadPudding object.
     */
    BadPudding():
        Card(CardType::TrapCard, SpawnType::Standard, Rarity::Common, 11, 1, 3, -2) {}

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