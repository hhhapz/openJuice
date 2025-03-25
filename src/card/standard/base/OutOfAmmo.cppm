/**
 * @file OutOfAmmo.cppm
 * @brief Implementation of the OutOfAmmo class.
 *
 * This file contains the implementation of the OutOfAmmo class, which represents the card "Out of Ammo" in the game.
 */

export module card.standard.base.OutOfAmmo;

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
 * @class OutOfAmmo
 * @brief Class representing the OutOfAmmo card.
 * 
 * @implements EventCard
 * @implements StandardCard
 *
 * The OutOfAmmo class implements both EventCard and StandardCard to represent the card "Out of Ammo" in the game.
 */
export class OutOfAmmo final: public EventCard, public StandardCard {
private:
    static constexpr char CARD_KEY[] = "CARD_EVENT_OUTOFAMMO"; ///< The key belonging to the card to query in TextManager
    static constexpr char ARTIST_KEY[] = "CARD_ARTIST_NERIUME"; ///< The key belonging to the name of the artist to query in TextManager

    /**
     * @brief No-operation function, should only be implemented by final classes.
     */
    void noop() const override {}
public:
    /**
     * @brief Constructor to initialise an OutOfAmmo object.
     */
    OutOfAmmo():
        Card(CardType::EventCard, SpawnType::Standard, Rarity::Uncommon, 18, 2, 3, -2) {}

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
        return 5;
    }

    /**
     * @brief Play the card.
     */
    void play() override {
        
    }
};