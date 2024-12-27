#pragma once

#include <print>

#include "stdint.hpp"

namespace GameInfo {
    constexpr usize GAME_MAX_WIDTH = 20;
    constexpr usize GAME_MAX_HEIGHT = 20;
    constexpr u8 MAX_PLAYERS = 4;
}

namespace Utility {
    void printHelp();
    void printCredits();
}