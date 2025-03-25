/**
 * @file MushroomCard.cppm
 * @brief Definition of the MushroomCard interface.
 *
 * This file contains the definition of the MushroomCard interface, which represents a Mushroom card in the game.
 */

export module engine.card.SpawnTypes:MushroomCard;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif
 
import engine.card.Card;
 
/**
 * @interface MushroomCard
 * @brief Interface representing a Mushroom card.
 *
 * @extends Card
 * 
 * The MushroomCard interface extends the Card abstract class and represents a Mushroom card with specific attributes.
 */
export class MushroomCard: virtual public Card {
protected:
    /**
     * @brief Default constructor for MushroomCard.
     */
    MushroomCard() = default;
};