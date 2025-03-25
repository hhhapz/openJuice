/**
 * @file concurrency.cppm
 * @brief Module file for standard library concurrency operations.
 *
 * This file contains the imports for the concurrency operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.concurrency;
#else
export module stdlib.concurrency;
#endif

#ifdef NO_RESERVED_STD
export import std.concurrency.Atomic;
export import std.concurrency.Barrier;
export import std.concurrency.ConditionVariable;
export import std.concurrency.Coroutine;
export import std.concurrency.Future;
export import std.concurrency.Latch;
export import std.concurrency.Mutex;
export import std.concurrency.Semaphore;
export import std.concurrency.SharedMutex;
export import std.concurrency.StopToken;
export import std.concurrency.Thread;
#else
export import stdlib.concurrency.Atomic;
export import stdlib.concurrency.Barrier;
export import stdlib.concurrency.ConditionVariable;
export import stdlib.concurrency.Coroutine;
export import stdlib.concurrency.Future;
export import stdlib.concurrency.Latch;
export import stdlib.concurrency.Mutex;
export import stdlib.concurrency.Semaphore;
export import stdlib.concurrency.SharedMutex;
export import stdlib.concurrency.StopToken;
export import stdlib.concurrency.Thread;
#endif

export using namespace stdlib;
