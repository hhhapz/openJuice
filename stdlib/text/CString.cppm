/**
 * @file CString.cppm
 * @brief Module file for standard library C-style string operations.
 *
 * This file contains the implementation of the C-style string operations in the standard library.
 */

module;

#include <cstring>

#ifdef NO_RESERVED_STD
export module std.text.CString;
#else
export module stdlib.text.CString;
#endif

/**
 * @namespace stdlib::string
 * @brief Wrapper namespace for standard library string operations.
 */
export namespace stdlib::string {
    using std::strcpy;
    using std::strncpy;
    using std::strcat;
    using std::strncat;
    using std::strxfrm;
    using std::strlen;
    using std::strcmp;
    using std::strncmp;
    using std::strcoll;
    using std::strchr;
    using std::strrchr;
    using std::strspn;
    using std::strcspn;
    using std::strpbrk;
    using std::strstr;
    using std::strtok;
    using std::memchr;
    using std::memcmp;
    using std::memset;
    using std::memcpy;
    using std::memmove;
    using std::strerror;
}
