/**
 * @file FTW.cppm
 * @brief Module file for Unix file tree traversal operations.
 *
 * This file contains the implementation of the Unix file tree traversal operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <ftw.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.FTW;
#else
export module stdlib.os.unix.FTW;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using ::FTW;

    using ::ftw;
    using ::ftw64;
    using ::nftw;
    using ::nftw64;
    #endif
}
