module;

#include <array>
#include <bitset>
#include <memory>

export module board.Panel;

import utility.Utility;

enum class PanelType {
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
    Ice, // 16 -Slide to the next panel without deducting from the move roll
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

enum class Direction {
    Up, // 0
    Left, // 1
    Right, // 2
    Down, //3
};

class Panel {
private:
    u16 panelID;
    PanelType type;
    PanelType alternativeType;
    std::bitset<4> enters;
    std::bitset<4> exits;
    std::array<std::weak_ptr<Panel>, 4> neighbours;
public:
    Panel(u16 id, PanelType type, const std::bitset<4>& enters, const std::bitset<4>& exits):
        panelID{id}, type{type}, enters{enters}, exits{exits} {}
    PanelType getType() const {
        return type;
    }
    void setType(PanelType newType) {
        type = newType;
    }
    void setNeighbour(Direction direction, std::shared_ptr<Panel> neighbour);
};