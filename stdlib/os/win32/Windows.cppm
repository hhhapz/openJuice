/**
 * @file Filesystem.cppm
 * @brief Module file for Win32 operations.
 *
 * This file contains the implementation of the Windows operations from the Windows API libraries.
 */

module;

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.win32.Windows;
#else
export module stdlib.os.win32.Windows;
#endif

/**
 * @namespace win32
 * @brief Wrapper namespace for Windows API operations.
 */
export namespace win32 {
    #ifdef _WIN32

    #endif
}
