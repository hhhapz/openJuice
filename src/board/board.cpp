#include "../../include/board/board.hpp"

Board::Board(u32 id) {
    const auto& boardData = BoardLibrary::getInstance().getBoard(id);

    
}

void Board::printBoardASCII() const {
    // Temporary, to hold the character used to print
    std::println("█");
}
