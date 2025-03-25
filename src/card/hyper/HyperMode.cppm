/**
 * @file HyperMode.cppm
 * @brief Implementation of the HyperMode class.
 *
 * This file contains the implementation of the HyperMode class, which represents the card "Hyper Mode" in the game.
 */

export module card.hyper.HyperMode;

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
 * @class HyperMode
 * @brief Class representing the HyperMode card.
 *
 * @implements BattleCard
 * @implements HyperCard
 *
 * The HyperMode class implements both BattleCard and HyperCard to represent the card "Hyper Mode" in the game.
 */
export class HyperMode final: public BattleCard, public HyperCard {
private:
    static constexpr char CARD_KEY[] = "CARD_HYPER_QP"; ///< The key belonging to the card to query in TextManager
    static constexpr char ARTIST_KEY[] = "CARD_ARTIST_MEGANE"; ///< The key belonging to the name of the artist to query in TextManager

    /**
     * @brief No-operation function, should only be implemented by final classes.
     */
    void noop() const override {}
public:
    /**
     * @brief Constructor to initialise a HyperMode object.
     */
    HyperMode():
        Card(CardType::BattleCard, SpawnType::Hyper, Rarity::None, 3, 1, -1, -1) {}

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
        return 10;
    }

    /**
     * @brief Play the card.
     */
    void play() override {
        
    }
};
