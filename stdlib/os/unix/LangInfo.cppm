/**
 * @file LangInfo.cppm
 * @brief Module file for Unix language information operations.
 *
 * This file contains the implementation of the Unix language information operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <langinfo.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.LangInfo;
#else
export module stdlib.os.unix.LangInfo;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using ::nl_langinfo;
    using ::nl_langinfo_l;
    #endif
}
