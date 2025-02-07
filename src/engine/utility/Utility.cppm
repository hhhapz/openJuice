module;

#include <print>
#include <stdexcept>
#include <tuple>

#ifdef _WIN32
#include <windows.h>
#else
#include <asm-generic/ioctls.h>
#include <sys/ioctl.h>
#include <unistd.h>
#endif

export module engine.utility.Utility;

export import :Primitives;

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
            throw std::runtime_error("Error getting terminal size.");
        }
        #else
        struct winsize w;
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
            rows = w.ws_row;
            cols = w.ws_col;
        } else {
            throw std::runtime_error("Error getting terminal size.");
        }
        #endif
        return {rows, cols};
    }
}