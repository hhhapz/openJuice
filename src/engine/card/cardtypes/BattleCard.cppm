/**
 * @file BattleCard.cppm
 * @brief Definition of the BattleCard interface.
 *
 * This file contains the definition of the BattleCard interface, which represents a Battle card in the game.
 */

export module engine.card.CardTypes:BattleCard;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

import engine.card.Card;

/**
 * @interface BattleCard
 * @brief Interface representing a Battle card.
 *
 * @extends Card
 * 
 * The BattleCard interface extends the Card abstract class and represents a battle card with specific attributes.
 */
export class BattleCard: virtual public Card {
protected:
    /**
     * @brief Default constructor for BattleCard.
     */
    BattleCard() = default;
};