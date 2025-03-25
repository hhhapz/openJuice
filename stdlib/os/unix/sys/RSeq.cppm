/**
 * @file RSeq.cppm
 * @brief Module file for Unix restartable sequences operations.
 *
 * This file contains the implementation of the Unix restartable sequences operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/rseq.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.RSeq;
#else
export module stdlib.os.unix.sys.RSeq;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using RSeqCPUIDState = ::rseq_cpu_id_state;
    using RSeqFlags = ::rseq_flags;
    using RSeqCSFlagsBit = ::rseq_cs_flags_bit;
    using RSeqCSFlags = ::rseq_cs_flags;
    using RSeqCS = ::rseq_cs;
    using RSeq = ::rseq;
    #endif
}
