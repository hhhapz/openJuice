/**
 * @file BoostCard.cppm
 * @brief Definition of the BoostCard interface.
 *
 * This file contains the definition of the BoostCard interface, which represents a Boost card in the game.
 */

export module engine.card.CardTypes:BoostCard;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.card.Card;

/**
 * @interface BoostCard
 * @brief Interface representing a Boost card.
 * 
 * @extends Card
 *
 * The BoostCard interface extends the Card abstract class and represents a Boost card with specific attributes.
 */
export class BoostCard: virtual public Card {
protected:
    /**
     * @brief Default constructor for BoostCard.
     */
    BoostCard() = default;
};