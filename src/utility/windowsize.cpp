#include "../../include/utility/windowsize.hpp"

namespace Utility {
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
    }
}