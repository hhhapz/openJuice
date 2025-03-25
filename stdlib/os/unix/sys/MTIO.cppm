/**
 * @file MTIO.cppm
 * @brief Module file for Unix magnetic tape I/O operations.
 *
 * This file contains the implementation of the Unix magnetic tape I/O operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/mtio.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.MTIO;
#else
export module stdlib.os.unix.sys.MTIO;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using MTOp = ::mtop;
    using MTGet = ::mtget;
    using MTTapeInfo = ::mt_tape_info;
    using MTPos = ::mtpos;
    using MTConfigInfo = ::mtconfiginfo;
    #endif
}
