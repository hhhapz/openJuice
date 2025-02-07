module;

export module engine.utility.Colours;

import engine.utility.Primitives;

export struct Colour {
    u8 r;
    u8 g;
    u8 b;
};

export namespace Colours {
    constexpr Colour BLACK = {0, 0, 0};
    constexpr Colour RED = {255, 0, 0};
    constexpr Colour GREEN = {0, 255, 0};
    constexpr Colour YELLOW = {255, 255, 0};
    constexpr Colour BLUE = {0, 0, 255};
    constexpr Colour MAGENTA = {255, 0, 255};
    constexpr Colour CYAN = {0, 255, 255};
    constexpr Colour WHITE = {255, 255, 255};

    constexpr const char* RESET_ANSI = "\033[0m";

    constexpr const char* BLACK_ANSI = "\033[30m";
    constexpr const char* RED_ANSI = "\033[31m";
    constexpr const char* GREEN_ANSI = "\033[32m";
    constexpr const char* YELLOW_ANSI = "\033[33m";
    constexpr const char* BLUE_ANSI = "\033[34m";
    constexpr const char* MAGENTA_ANSI = "\033[35m";
    constexpr const char* CYAN_ANSI = "\033[36m";
    constexpr const char* WHITE_ANSI = "\033[37m";

    constexpr const char* BOLD_BLACK_ANSI = "\033[1m\033[30m";
    constexpr const char* BOLD_RED_ANSI = "\033[1m\033[31m";
    constexpr const char* BOLD_GREEN_ANSI = "\033[1m\033[32m";
    constexpr const char* BOLD_YELLOW_ANSI = "\033[1m\033[33m";
    constexpr const char* BOLD_BLUE_ANSI = "\033[1m\033[34m";
    constexpr const char* BOLD_MAGENTA_ANSI = "\033[1m\033[35m";
    constexpr const char* BOLD_CYAN_ANSI = "\033[1m\033[36m";
    constexpr const char* BOLD_WHITE_ANSI = "\033[1m\033[37m";
}