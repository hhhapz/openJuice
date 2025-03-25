/**
 * @file Card.cppm
 * @brief Definition of the Card abstract class and related enums.
 *
 * This file contains the definition of the Card abstract class and related enums, which represent different types of cards in the game.
 */

export module engine.card.Card;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.utility.Interfaces;

/**
 * @enum CardType
 * @brief Enumeration for card types.
 * 
 * The CardType enumeration defines the types of cards in the game.
 */
export enum class CardType {
    BattleCard, ///< Battle card type.
    BoostCard, ///< Boost card type.
    EventCard, ///< Event card type.
    GiftCard, ///< Gift card type.
    TrapCard ///< Trap card type.
};

/**
 * @enum SpawnType
 * @brief Enumeration for card spawn types.
 * 
 * The SpawnType enumeration defines the spawn types of cards in the game.
 */
export enum class SpawnType {
    Standard, ///< Standard spawn type.
    Hyper, ///< Hyper spawn type.
    Mushroom, ///< Mushroom spawn type.
};

/**
 * @enum Rarity
 * @brief Enumeration for card rarities.
 * 
 * The Rarity enumeration defines the rarities of cards in the game.
 */
export enum class Rarity {
    None, ///< No rarity (for hyper cards).
    Common, ///< Common rarity.
    Uncommon, ///< Uncommon rarity.
    Rare ///< Rare rarity.
};

/**
 * @class Card
 * @brief Abstract class representing a card.
 * 
 * The Card abstract class represents a card in the game with the following attributes: type, rarity, ID, and level.
 *
 * @implements FinalOnly
 * @implements KeyQueryable
 */
export class Card: public FinalOnly, public KeyQueryable {
private:
    const CardType cardType; ///< The card type of the card.
    const SpawnType spawnType; ///< The spawn type of the card.
    const Rarity rarity; ///< The rarity of the card.
    const u16 id; ///< The ID of the card.
    const u8 level; ///< The level of the card.
    const i8 limitPerDeck; ///< The limit of the card per deck (-1 if hyper, positive otherwise).
    const i8 deckPoints; ///< The deck points of the card (-2 if cannot be played in co-op, -1 if hyper, non-negative otherwise).
protected:
    /**
     * @brief Default constructor to initialise a Card object.
     */
    Card():
        cardType{static_cast<CardType>(0)}, spawnType{static_cast<SpawnType>(0)}, rarity{static_cast<Rarity>(0)}, 
        id{0}, level{0}, limitPerDeck{0}, deckPoints{0} {}
public:
    /**
     * @brief Constructor to initialise a Card object.
     *
     * @param cardType The card type of the card.
     * @param spawnType The spawn type of the card.
     * @param rarity The rarity of the card.
     * @param id The ID of the card.
     * @param level The level of the card.
     * @param limit The limit of the card per deck.
     * @param deckPoints The deck points of the card.
     */
    Card(CardType cardType, SpawnType spawnType, Rarity rarity, u16 id, u8 level, i8 limit, i8 deckPoints):
        cardType{cardType}, spawnType{spawnType}, rarity{rarity}, id{id}, level{level}, limitPerDeck{limit}, deckPoints{deckPoints} {}

    /**
     * @brief Get the card type of the card.
     * @return The card type of the card.
     */
    CardType getCardType() const {
        return cardType;
    }

    /**
     * @brief Get the spawn type of the card.
     * @return The spawn type of the card.
     */
    SpawnType getSpawnType() const {
        return spawnType;
    }

    /**
     * @brief Get the rarity of the card.
     * @return The rarity of the card.
     * 
     * The rarity of the card.
     * Only Standard cards have rarities.
     */
    Rarity getRarity() const {
        return rarity;
    }

    /**
     * @brief Get the ID of the card.
     * @return The ID of the card.
     */
    u16 getID() const {
        return id;
    }

    /**
     * @brief Get the level of the card.
     * @return The level of the card.
     *
     * The level of the card is used to determine the card's power and cost.
     * Returns an unsigned integer - 0 if the card is a Mushroom card.
     */
    u8 getLevel() const {
        return level;
    }

    /**
     * @brief Get the limit of the card per deck.
     * @return The limit of the card per deck.
     *
     * Returns a signed integer - returns -1 if the card is not a Standard card, positive otherwise.
     */
    i8 getLimit() const {
        return limitPerDeck;
    }

    /**
     * @brief Get the deck points of the card.
     * @return The deck points of the card.
     *
     * Returns a signed integer - returns -2 if the card cannot be played in co-op, -1 if the card is not a Standard card, non-negative otherwise.
     */
    i8 getDeckPoints() const {
        return deckPoints;
    }

    /**
     * @brief Play the card.
     * 
     * This is a pure virtual function that must be implemented by derived classes.
     */
    virtual void play() = 0;

    /**
     * @brief Get the name of the card.
     * @return The name of the card.
     * 
     * This is a pure virtual function that must be implemented by derived classes.
     */
    inline virtual String getName() const {
        return "";
    }

    /**
     * @brief Get the description of the card.
     * @return The description of the card.
     */
    inline virtual String getDescription() const {
        return "";
    }

    /**
     * @brief Get the flavour text of the card.
     * @return The flavour text of the card.
     */
    inline virtual String getFlavour() const {
        return "";
    }

    /**
     * @brief Get the card artist name.
     * @return The card artist name.
     */
    inline virtual String getArtistName() const {
        return "";
    }

    /**
     * @brief Get the cost of the card.
     * @return The cost of the card.
     * 
     * This is a pure virtual function that must be implemented by derived classes.
     * Returns a signed integer - returns -1 if the cost is not a fixed value.
     */
    virtual i16 getCost() const = 0;
};
