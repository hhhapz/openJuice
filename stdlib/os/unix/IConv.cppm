/**
 * @file IConv.cppm
 * @brief Module file for Unix codeset conversion operations.
 *
 * This file contains the implementation of the Unix codeset conversion operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <iconv.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.IConv;
#else
export module stdlib.os.unix.IConv;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using ::iconv_close;
    using ::iconv_open;
    using ::iconv;
    #endif
}
