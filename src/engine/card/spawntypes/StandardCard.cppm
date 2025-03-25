/**
 * @file StandardCard.cppm
 * @brief Definition of the StandardCard interface.
 *
 * This file contains the definition of the StandardCard interface, which represents a Standard card in the game.
 */

export module engine.card.SpawnTypes:StandardCard;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif
 
import engine.card.Card;
 
/**
 * @interface StandardCard
 * @brief Interface representing a Standard card.
 *
 * @extends Card
 * 
 * The StandardCard interface extends the Card abstract class and represents a Standard card with specific attributes.
 */
export class StandardCard: virtual public Card {
protected:
    /**
     * @brief Default constructor for StandardCard.
     */
    StandardCard() = default;
};