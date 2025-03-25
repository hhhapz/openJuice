/**
 * @file Panel.cppm
 * @brief Implementation of the Panel class.
 *
 * This file contains the implementation of the Panel class, which represents a panel on the game board.
 */

export module engine.board.Panel;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.mem;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.mem;
#endif

using namespace collections;
using mem::SharedPtr, mem::WeakPtr;

/**
 * @enum PanelType
 * @brief Enumeration for panel types.
 *
 * The PanelType enumeration defines the types of panels in the game.
 */
export enum class PanelType {
    Home, // 0 - Home panel - level up on achieving norma and heal 1 HP
    Neutral, // 1 - Nothing happens
    Bonus, // 2 - Roll to gain star amount multiplied by level
    Bonus2, // 3 - Roll twice the dice for Bonus tile
    Drop, // 4 - Roll to lose star amount multiplied by level
    Drop2, // 5 - Roll twice the dice for Drop tile
    Draw, // 6 - Draw a card from the top of the deck
    Draw2, // 7 - Draw 2 cards from the top of the deck
    Warp, // 8 - Teleport to any Warp or Warp Move panel
    Warp_Move, // 9 - Teleport to any Warp or Warp Move panel, then roll/move again
    Warp_Move2, // 10 - Roll twice the dice for Warp Move panel
    Encounter, // 11 - Face a random enemy unit in combat
    Encounter2, // 12 - Trigger Encounter panel, gain twice the wins upon KOing the unit
    Boss_Encounter, // 13 - Face this board's boss in combat
    Move, // 14 - Roll and move again
    Move2, // 15 - Roll twice the dice for Move panel
    Ice, // 16 - Slide to the next panel without deducting from the move roll
    Goo, // 17 - Deduct 2 points from the move roll instead of 1
    Heal, // 18 - Heal 1 HP
    Heal2, // 19 - Heal 2 HP
    Damage, // 20 - Take 1 damage
    Damage2, // 21 - Take 2 damage
    Minigame, // 22 - UNUSED, Play a random minigame
    Boss_Home, // 23 - UNUSED, Spawn panel for Boss, face this board's boss in combat
    Decoration, // 24 - UNUSED, gain 1 decoration
    Player_Encounter // 25 - UNUSED, face a random player in combat
};

/**
 * @enum Direction
 * @brief Enumeration for directions.
 *
 * The Direction enumeration defines the four cardinal directions.
 */
export enum class Direction {
    Up,    // 0
    Left,  // 1
    Right, // 2
    Down,  // 3
};

/**
 * @class Panel
 * @brief Class representing a panel on the game board.
 *
 * The Panel class represents a panel on the game board with attributes such as type, neighbours, and entry/exit directions.
 */
export class Panel {
private:
    u16 panelID; ///< The ID of the panel.
    PanelType type; ///< The type of the panel.
    PanelType alternativeType; ///< The alternative type of the panel.
    BitSet<4> enters; ///< The directions from which the panel can be entered.
    BitSet<4> exits; ///< The directions from which the panel can be exited.
    Array<WeakPtr<Panel>, 4> neighbours; ///< The neighbouring panels.
public:
    /**
     * @brief Constructor to initialise a Panel object.
     * @param id The ID of the panel.
     * @param type The type of the panel.
     * @param enters The directions from which the panel can be entered.
     * @param exits The directions from which the panel can be exited.
     */
    Panel(u16 id, PanelType type, const BitSet<4>& enters, const BitSet<4>& exits):
        panelID{id}, type{type}, enters{enters}, exits{exits} {}

    /**
     * @brief Get the type of the panel.
     * @return The type of the panel.
     */
    PanelType getType() const {
        return type;
    }

    /**
     * @brief Set the type of the panel.
     * @param newType The new type of the panel.
     */
    void setType(PanelType newType) {
        type = newType;
    }

    /**
     * @brief Set the neighbour of the panel in a specific direction.
     * @param direction The direction of the neighbour.
     * @param neighbour The neighbouring panel.
     */
    void setNeighbour(Direction direction, SharedPtr<Panel> neighbour) {
        #ifndef NDEBUG
        neighbours.at(static_cast<usize>(direction)) = neighbour;
        #else
        neighbours[static_cast<usize>(direction)] = neighbour;
        #endif
    }

    /**
     * @brief Get the neighbour of the panel in a specific direction.
     * @param direction The direction of the neighbour.
     * @return The neighbouring panel.
     */
    SharedPtr<Panel> getNeighbour(Direction direction) const {
        #ifndef NDEBUG
        return neighbours.at(static_cast<usize>(direction)).lock();
        #else
        return neighbours[static_cast<usize>(direction)].lock();
        #endif
    }
};
