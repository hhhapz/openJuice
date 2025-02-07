module;

#include <print>

export module utility.Utility;

export using i8 = int8_t;
export using i16 = int16_t;
export using i32 = int32_t;
export using i64 = int64_t;
export using u8 = uint8_t;
export using u16 = uint16_t;
export using u32 = uint32_t;
export using u64 = uint64_t;
export using f32 = float;
export using f64 = double;
export using usize = size_t;

export namespace GameInfo {
    constexpr usize GAME_MAX_WIDTH = 20;
    constexpr usize GAME_MAX_HEIGHT = 20;
    constexpr u8 MAX_PLAYERS = 4;
}

export namespace Utility {
    void printHelp() {
        std::println("Help message");
    }
    void printCredits() {
        std::println("Credits message");
    }
    std::tuple<i32, i32> getTerminalSize() {
        i32 rows = 0;
        i32 cols = 0;
        #ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO cbsi;
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
            rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
            cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        } else {
            std::println(stderr, "Error getting terminal size.")
        }
        #endif
    }
}