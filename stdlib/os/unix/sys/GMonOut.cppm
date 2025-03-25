/**
 * @file GmonOut.cppm
 * @brief Module file for Unix operations.
 *
 * This file contains the implementation of the Unix operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/gmon_out.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.GMonOut;
#else
export module stdlib.os.unix.sys.GMonOut;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using GMonHdr = ::gmon_hdr;
    using GMonHistHdr = ::gmon_hist_hdr;
    using GMonCGArcRecord = ::gmon_cg_arc_record;
    #endif
}
