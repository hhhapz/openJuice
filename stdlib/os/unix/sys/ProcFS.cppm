/**
 * @file ProcFS.cppm
 * @brief Module file for Unix core file/libthread_db operations.
 *
 * This file contains the implementation of the Unix core file/libthread_db operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/procfs.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.ProcFS;
#else
export module stdlib.os.unix.sys.ProcFS;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ELFSigInfo = ::elf_siginfo;
    using ELFPRStatus = ::elf_prstatus;
    using ELFPRPSInfo = ::elf_prpsinfo;
    #endif
}
