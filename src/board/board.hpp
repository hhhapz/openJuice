#pragma once

#include "graph.hpp"

enum class Panels {
    Home, // Home panel - level up on achieving norma and heal 1 HP
    Neutral, // Nothing happens
    Bonus, // Roll to gain star amount multiplied by level
    Bonus2, // Roll twice the dice for Bonus tile
    Drop, // Roll to lose star amount multiplied by level
    Drop2, // Roll twice the dice for Drop tile
    Draw, // Draw a card from the top of the deck
    Draw2, // Draw 2 cards from the top of the deck
    Warp, // Teleport to any Warp or Warp Move panel
    Warp_Move, // Teleport to any Warp or Warp Move panel, then roll/move again
    Warp_Move2, // Roll twice the dice for Warp Move panel
    Encounter, // Face a random enemy unit in combat
    Encounter2, // Trigger Encounter panel, gain twice the wins upon KOing the unit
    Boss_Encounter, // Face this board's boss in combat
    Move, // Roll and move again
    Move2, // Roll twice the dice for Move panel
    Ice, // Slide to the next panel without deducting from the move roll
    Goo, // Deduct 2 points from the move roll instead of 1
    Heal, // Heal 1 HP
    Heal2, // Heal 2 HP
    Damage, // Take 1 damage
    Damage2, // Take 2 damage
    Minigame, // UNUSED, Play a random minigame
    Boss_Home, // UNUSED, Spawn panel for Boss, face this board's boss in combat
    Decoration, // UNUSED, gain 1 decoration
    Player_Encounter // UNUSED, face a random player in combat
};

class Board: public Graph<Panels> {

};