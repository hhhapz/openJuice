/**
 * @file Win32.cppm
 * @brief Module file for Win32 operations.
 *
 * This file contains the implementation of the Windows operations from the Windows API libraries.
 */

#ifdef NO_RESERVED_STD
export module std.os.Win32;
#else
export module stdlib.os.Win32;
#endif

#ifdef NO_RESERVED_STD
export import std.os.win32.Windows;
#else
export import stdlib.os.win32.Windows;
#endif
