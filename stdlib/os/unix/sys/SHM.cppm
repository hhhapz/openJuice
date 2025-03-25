/**
 * @file SHM.cppm
 * @brief Module file for Unix XSI shared memory operations.
 *
 * This file contains the implementation of the Unix XSI shared memory operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/shm.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.SHM;
#else
export module stdlib.os.unix.sys.SHM;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::shmctl;
    using ::shmget;
    using ::shmat;
    using ::shmdt;
    #endif
}
