/**
 * @file BoardInfo.cppm
 * @brief Definition of the BoardInfo struct.
 *
 * This file contains the definition of the BoardInfo struct, which aggregates key information about boards.
 */

export module engine.board.BoardInfo;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
#else
import stdlib.core;
import stdlib.collections;
#endif

import engine.utility.GameInfo;

using namespace stdlib::collections;

/**
 * @struct BoardInfo
 * @brief Struct aggregating key information about boards.
 * 
 * The BoardInfo struct aggregates key information about boards, such as ID, name, dimensions, and home panels.
 */
export struct BoardInfo {
    u32 id; ///< The ID of the board.
    String boardName; ///< The name of the board.
    u8 boardWidth; ///< The width of the board.
    u8 boardHeight; ///< The height of the board.
    Array<Pair<u8, u8>, GameInfo::MAX_PLAYERS> homePanels; ///< The home panels for each player.
};