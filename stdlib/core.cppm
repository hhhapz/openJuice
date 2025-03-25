/**
 * @file core.cppm
 * @brief Module file for standard library core operations.
 *
 * This file contains the imports for the core operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.core;
#else
export module stdlib.core;
#endif

#ifdef NO_RESERVED_STD
export import std.core.Any;
export import std.core.Compare;
export import std.core.Concepts;
export import std.core.CStdDef;
export import std.core.Exceptions;
export import std.core.Execution;
export import std.core.Expected;
export import std.core.Functional;
export import std.core.InitializerList;
export import std.core.Limits;
export import std.core.Optional;
export import std.core.Primitives;
export import std.core.String;
export import std.core.Variant;
#else
export import stdlib.core.Any;
export import stdlib.core.Compare;
export import stdlib.core.Concepts;
export import stdlib.core.CStdDef;
export import stdlib.core.Exceptions;
export import stdlib.core.Execution;
export import stdlib.core.Expected;
export import stdlib.core.Functional;
export import stdlib.core.InitializerList;
export import stdlib.core.Limits;
export import stdlib.core.Optional;
export import stdlib.core.Primitives;
export import stdlib.core.String;
export import stdlib.core.Variant;
#endif

export using namespace stdlib;
