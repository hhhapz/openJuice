/**
 * @file ImOnFire.cppm
 * @brief Implementation of the ImOnFire class.
 *
 * This file contains the implementation of the ImOnFire class, which represents the card "I'm on Fire!" in the game.
 */

export module card.standard.base.ImOnFire;

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
 * @class ImOnFire
 * @brief Class representing the ImOnFire card.
 * 
 * @implements BattleCard
 * @implements StandardCard
 *
 * The ImOnFire class implements both BattleCard and StandardCard to represent the card "I'm on Fire!" in the game.
 */
export class ImOnFire final: public BattleCard, public StandardCard {
private:
    static constexpr char CARD_KEY[] = "CARD_BATTLE_ONFIRE"; ///< The key belonging to the card to query in TextManager
    static constexpr char ARTIST_KEY[] = "CARD_ARTIST_TORI"; ///< The key belonging to the name of the artist to query in TextManager

    /**
     * @brief No-operation function, should only be implemented by final classes.
     */
    void noop() const override {}
public:
    /**
     * @brief Constructor to initialise an ImOnFire object.
     */
    ImOnFire():
        Card(CardType::BattleCard, SpawnType::Standard, Rarity::Common, 7, 1, 3, 2) {}

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