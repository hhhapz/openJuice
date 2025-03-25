/**
 * @file CSetJmp.cppm
 * @brief Module file for standard library C-style jumping operations.
 *
 * This file contains the implementation of the C-style jumping operations in the standard library.
 */

module;

#include <csetjmp>

#ifdef NO_RESERVED_STD
export module std.sys.CSetJmp;
#else
export module stdlib.sys.CSetJmp;
#endif

/**
 * @namespace stdlib::sys
 * @brief Wrapper namespace for standard library system operations.
 */
export namespace stdlib::sys {
    using JmpBuf = std::jmp_buf;

    using std::longjmp;
}
