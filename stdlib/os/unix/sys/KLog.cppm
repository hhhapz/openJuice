/**
 * @file KLog.cppm
 * @brief Module file for Unix operations.
 *
 * This file contains the implementation of the Unix operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/klog.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.KLog;
#else
export module stdlib.os.unix.sys.KLog;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::klogctl;
    #endif
}
