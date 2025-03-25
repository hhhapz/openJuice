/**
 * @file HyperCard.cppm
 * @brief Definition of the HyperCard interface.
 *
 * This file contains the definition of the HyperCard interface, which represents a Hyper card in the game.
 */

export module engine.card.SpawnTypes:HyperCard;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif
 
import engine.card.Card;
 
/**
 * @interface HyperCard
 * @brief Interface representing a Hyper card.
 *
 * @extends Card
 * 
 * The HyperCard interface extends the Card abstract class and represents a Hyper card with specific attributes.
 */
export class HyperCard: virtual public Card {
protected:
    /**
     * @brief Default constructor for HyperCard.
     */
    HyperCard() = default;
};