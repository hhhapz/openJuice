/**
 * @file CStdLib.cppm
 * @brief Module file for standard library C-style memory operations.
 *
 * This file contains the implementation of the C-style memory operations in the standard library.
 */

module;

#include <cstdlib>

#ifdef NO_RESERVED_STD
export module std.mem.CStdLib;
#else
export module stdlib.mem.CStdLib;
#endif

/**
 * @namespace stdlib::mem
 * @brief Wrapper namespace for standard library memory operations.
 */
export namespace stdlib::mem {
    using std::malloc;
    using std::aligned_alloc;
    using std::calloc;
    using std::realloc;
    using std::free;
}
