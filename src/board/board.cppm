module;

#include <array>
#include <memory>
#include <print>
#include <utility>

#include <toml++/toml.hpp>

export module board.Board;

import board.Boards;
import board.Panel;
import utility.Utility;

static constexpr std::array<std::pair<i32, i32>, 8> directionOffsets = {{
    {-1, -1}, {-1,  0}, {-1,  1}, // Top-left, Top, Top-right
    { 0,  1},           { 0,  1}, // Left, Right
    { 1, -1}, { 1,  0}, { 1,  1}  // Bottom-left, Bottom, Bottom-right
}};

export class Board {
private:
    std::array<std::array<std::unique_ptr<Panel>, GameInfo::GAME_MAX_WIDTH>, GameInfo::GAME_MAX_HEIGHT> gameBoard;
    std::array<std::pair<u8, u8>, GameInfo::MAX_PLAYERS> homePanels;
    u8 boardWidth;
    u8 boardHeight;
public:
    Board(u32 id) {
        const BoardInfo& boardData = BoardLibrary::getInstance().getBoard(id);
    }

    void printBoardASCII() const {
        std::println("█");
    }
};