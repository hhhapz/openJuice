/**
 * @file Sem.cppm
 * @brief Module file for Unix XSI semaphore operations.
 *
 * This file contains the implementation of the Unix XSI semaphore operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/sem.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.Sem;
#else
export module stdlib.os.unix.sys.Sem;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using SemInfo = ::seminfo;
    using SemBuf = ::sembuf;

    using ::semctl;
    using ::semget;
    using ::semop;
    using ::semtimedop;
    #endif
}
