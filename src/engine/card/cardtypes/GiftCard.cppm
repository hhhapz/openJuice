/**
 * @file GiftCard.cppm
 * @brief Definition of the GiftCard interface.
 *
 * This file contains the definition of the GiftCard interface, which represents a Gift card in the game.
 */

export module engine.card.CardTypes:GiftCard;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.card.Card;

/**
 * @interface GiftCard
 * @brief Interface representing a Gift card.
 * 
 * @extends Card
 *
 * The GiftCard interface extends the Card abstract class and represents a Gift card with specific attributes.
 */
export class GiftCard: virtual public Card {
protected:
    /**
     * @brief Default constructor for GiftCard.
     */
    GiftCard() = default;
};