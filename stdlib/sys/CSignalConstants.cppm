/**
 * @file CSignalConstants.cppm
 * @brief Module file for constants of the standard library C-style signal operations.
 *
 * This file contains the implementation of the constants of the C-style signal operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.sys.CSignal:Constants;
#else
export module stdlib.sys.CSignal:Constants;
#endif

/**
 * @namespace stdlib::sys
 * @brief Wrapper namespace for standard library system operations.
 */
export namespace stdlib::sys {
    constexpr inline int SIGHUP = 1;    ///< Hangup.
    constexpr inline int SIGINT = 2;    ///< Interactive attention signal.
    constexpr inline int SIGQUIT = 3;   ///< Quit.
    constexpr inline int SIGILL = 4;    ///< Illegal instruction.
    constexpr inline int SIGTRAP = 5;   ///< Trace/breakpoint trap.
    constexpr inline int SIGABRT = 6;   ///< Abnormal termination.
    constexpr inline int SIGBUS = 7;    ///< Bus error.
    constexpr inline int SIGFPE = 8;    ///< Erroneous arithmetic operation.
    constexpr inline int SIGKILL = 9;   ///< Killed.
    constexpr inline int SIGUSR1 = 10;  ///< User-defined signal 1.
    constexpr inline int SIGSEGV = 11;  ///< Invalid access to storage.
    constexpr inline int SIGUSR2 = 12;  ///< User-defined signal 2.
    constexpr inline int SIGPIPE = 13;  ///< Broken pipe.
    constexpr inline int SIGALRM = 14;  ///< Alarm clock.
    constexpr inline int SIGTERM = 15;  ///< Termination request.
    constexpr inline int SIGSTKFLT = 16;///< Stack fault (obsolete).
    constexpr inline int SIGCHLD = 17;  ///< Child terminated or stopped.
    constexpr inline int SIGCONT = 18;  ///< Continue.
    constexpr inline int SIGSTOP = 19;  ///< Stop, unblockable.
    constexpr inline int SIGTSTP = 20;  ///< Keyboard stop.
    constexpr inline int SIGTTIN = 21;  ///< Background read from control terminal.
    constexpr inline int SIGTTOU = 22;  ///< Background write to control terminal.
    constexpr inline int SIGURG = 23;   ///< Urgent data is available at a socket.
    constexpr inline int SIGXCPU = 24;  ///< CPU time limit exceeded.
    constexpr inline int SIGXFSZ = 25;  ///< File size limit exceeded.
    constexpr inline int SIGVTALRM = 26;///< Virtual timer expired.
    constexpr inline int SIGPROF = 27;  ///< Profiling timer expired.
    constexpr inline int SIGWINCH = 28; ///< Window size change (4.3 BSD, Sun).
    constexpr inline int SIGPOLL = 29;  ///< Pollable event occurred (System V).
    constexpr inline int SIGPWR = 30;   ///< Power failure imminent.
    constexpr inline int SIGSYS = 31;   ///< Bad system call.

    /* Historical signals and archaic names for compatibility */
    constexpr inline int SIGIO = SIGPOLL;   ///< I/O now possible (4.2 BSD).
    constexpr inline int SIGIOT = SIGABRT;  ///< IOT instruction, abort() on a PDP-11.
    constexpr inline int SIGCLD = SIGCHLD;  ///< Old System V name for SIGCHLD.
}
