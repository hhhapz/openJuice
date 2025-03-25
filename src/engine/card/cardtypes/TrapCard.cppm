/**
 * @file TrapCard.cppm
 * @brief Definition of the TrapCard interface.
 *
 * This file contains the definition of the TrapCard interface, which represents a Trap card in the game.
 */

export module engine.card.CardTypes:TrapCard;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.card.Card;

/**
 * @interface TrapCard
 * @brief Interface representing a Trap card.
 *
 * @extends Card
 * 
 * The TrapCard interface extends the Card abstract class and represents a Trap card with specific attributes.
 */
export class TrapCard: virtual public Card {
protected:
    /**
     * @brief Default constructor for TrapCard.
     */
    TrapCard() = default;
};