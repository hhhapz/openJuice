/**
 * @file EventCard.cppm
 * @brief Definition of the EventCard interface.
 *
 * This file contains the definition of the EventCard interface, which represents an Event card in the game.
 */

export module engine.card.CardTypes:EventCard;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.card.Card;

/**
 * @interface EventCard
 * @brief Interface representing an Event card.
 * 
 * @extends Card
 *
 * The EventCard interface extends the Card abstract class and represents an Event card with specific attributes.
 */
export class EventCard: virtual public Card {
protected:
    /**
     * @brief Default constructor for EventCard.
     */
    EventCard() = default;
};