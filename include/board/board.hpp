#pragma once

#include <array>
#include <memory>
#include <utility>

#include <toml++/toml.hpp>

#include "boards.hpp"
#include "panel.hpp"
#include "../utility/utility.hpp"

static constexpr std::array<std::pair<i32, i32>, 8> directionOffsets = {{
    {-1, -1}, {-1,  0}, {-1,  1}, // Top-left, Top, Top-right
    { 0,  1},           { 0,  1}, // Left, Right
    { 1, -1}, { 1,  0}, { 1,  1}  // Bottom-left, Bottom, Bottom-right
}};

class Board {
private:
    std::array<std::array<std::unique_ptr<Panel>, GameInfo::GAME_MAX_WIDTH>, GameInfo::GAME_MAX_HEIGHT> gameBoard;
    std::array<std::pair<u8, u8>, GameInfo::MAX_PLAYERS> homePanels;
    u8 boardWidth;
    u8 boardHeight;
public:
    Board(u32 id);
    void printBoardASCII() const;
};