/**
 * @file Colours.cppm
 * @brief Definition of the Colour struct and Colours namespace.
 *
 * This file contains the definition of the Colour struct and the Colours namespace, which provides predefined colours and ANSI colour codes.
 */

export module engine.utility.Colours;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

/**
 * @struct Colour
 * @brief Struct representing a colour with red, green, and blue components.
 */
export struct Colour {
    u8 r; ///< Red component.
    u8 g; ///< Green component.
    u8 b; ///< Blue component.
};

/**
 * @namespace Colours
 * @brief Namespace for predefined colours and ANSI colour codes.
 */
export namespace Colours {
    constexpr Colour BLACK = {0, 0, 0}; ///< Black colour.
    constexpr Colour RED = {255, 0, 0}; ///< Red colour.
    constexpr Colour GREEN = {0, 255, 0}; ///< Green colour.
    constexpr Colour YELLOW = {255, 255, 0}; ///< Yellow colour.
    constexpr Colour BLUE = {0, 0, 255}; ///< Blue colour.
    constexpr Colour MAGENTA = {255, 0, 255}; ///< Magenta colour.
    constexpr Colour CYAN = {0, 255, 255}; ///< Cyan colour.
    constexpr Colour WHITE = {255, 255, 255}; ///< White colour.

    constexpr inline char RESET_ANSI[] = "\033[0m"; ///< ANSI code to reset colour.

    constexpr inline char BLACK_ANSI[] = "\033[30m"; ///< ANSI code for black colour.
    constexpr inline char RED_ANSI[] = "\033[31m"; ///< ANSI code for red colour.
    constexpr inline char GREEN_ANSI[] = "\033[32m"; ///< ANSI code for green colour.
    constexpr inline char YELLOW_ANSI[] = "\033[33m"; ///< ANSI code for yellow colour.
    constexpr inline char BLUE_ANSI[] = "\033[34m"; ///< ANSI code for blue colour.
    constexpr inline char MAGENTA_ANSI[] = "\033[35m"; ///< ANSI code for magenta colour.
    constexpr inline char CYAN_ANSI[] = "\033[36m"; ///< ANSI code for cyan colour.
    constexpr inline char WHITE_ANSI[] = "\033[37m"; ///< ANSI code for white colour.

    constexpr inline char BOLD_BLACK_ANSI[] = "\033[1m\033[30m"; ///< ANSI code for bold black colour.
    constexpr inline char BOLD_RED_ANSI[] = "\033[1m\033[31m"; ///< ANSI code for bold red colour.
    constexpr inline char BOLD_GREEN_ANSI[] = "\033[1m\033[32m"; ///< ANSI code for bold green colour.
    constexpr inline char BOLD_YELLOW_ANSI[] = "\033[1m\033[33m"; ///< ANSI code for bold yellow colour.
    constexpr inline char BOLD_BLUE_ANSI[] = "\033[1m\033[34m"; ///< ANSI code for bold blue colour.
    constexpr inline char BOLD_MAGENTA_ANSI[] = "\033[1m\033[35m"; ///< ANSI code for bold magenta colour.
    constexpr inline char BOLD_CYAN_ANSI[] = "\033[1m\033[36m"; ///< ANSI code for bold cyan colour.
    constexpr inline char BOLD_WHITE_ANSI[] = "\033[1m\033[37m"; ///< ANSI code for bold white colour.
}