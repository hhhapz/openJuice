/**
 * @file EngineUtility.cppm
 * @brief Implementation of utility functions for the engine.
 *
 * This file contains the implementation of utility functions for the engine, such as hashing strings and getting terminal size.
 */

module;

#ifdef _WIN32
#include <windows.h>
#else
#include <asm-generic/ioctls.h>
#include <unistd.h>
#endif

export module engine.utility.EngineUtility;

export import :DebugLogger;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.os;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.os;
#endif

using namespace collections;

/**
 * @namespace engineutility
 * @brief Namespace for engine utility functions.
 */
export namespace engineutility {
    /**
     * @namespace strings
     * @brief Namespace for string manipulating functions.
     */
    namespace strings {
        /**
         * @brief Hash a string using a polynomial rolling hash function.
         * @param s The string to hash.
         * @return The hash value of the string.
         */
        constexpr usize hashString(const char* s) {
            const i64 p = 131;
            const i64 m = 4294967291;
            i64 total = 0;
            i64 currentMultiplier = 1;
            for (usize i = 0; s[i] != '\0'; ++i) {
                total = (total + currentMultiplier * s[i]) % m;
                currentMultiplier = (currentMultiplier * p) % m;
            }
            return total;
        }

        /**
         * @brief Trims leading and trailing whitespace from a string.
         * @param str The string to trim.
         * @return The trimmed string.
         */
        String trimString(const String& str) {
            const auto start = str.find_first_not_of(" \t\r\n");
            if (start == String::npos) 
                return "";
            
            const auto end = str.find_last_not_of(" \t\r\n");
            return str.substr(start, end - start + 1);
        }
    }

    /**
     * @brief Get the size of the terminal.
     * @return A tuple containing the number of rows and columns of the terminal.
     * @throws RuntimeException (std::runtime_error) if there is an error getting the terminal size.
     */
    Tuple<i32, i32> getTerminalSize() {
        i32 rows = 0;
        i32 cols = 0;
        #ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO cbsi;
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
            rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
            cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        } else {
            throw RuntimeException("Error getting terminal size.");
        }
        #else
        stdlib::os::posix::sys::WinSize w;
        if (stdlib::os::posix::sys::ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
            rows = w.ws_row;
            cols = w.ws_col;
        } else {
            throw RuntimeException("Error getting terminal size.");
        }
        #endif
        return {rows, cols};
    }
}
