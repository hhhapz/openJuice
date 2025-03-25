/**
 * @file collections.cppm
 * @brief Module file for standard library collection operations.
 *
 * This file contains the imports for the collection operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.collections;
#else
export module stdlib.collections;
#endif

#ifdef NO_RESERVED_STD
export import std.collections.Array;
export import std.collections.BitSet;
export import std.collections.Deque;
export import std.collections.ForwardList;
export import std.collections.IntegerSequence;
export import std.collections.List;
export import std.collections.Map;
export import std.collections.Pair;
export import std.collections.Queue;
export import std.collections.Set;
export import std.collections.Stack;
export import std.collections.Tuple;
export import std.collections.UnorderedMap;
export import std.collections.UnorderedSet;
export import std.collections.ValArray;
export import std.collections.Vector;
#else
export import stdlib.collections.Array;
export import stdlib.collections.BitSet;
export import stdlib.collections.Deque;
export import stdlib.collections.ForwardList;
export import stdlib.collections.IntegerSequence;
export import stdlib.collections.List;
export import stdlib.collections.Map;
export import stdlib.collections.Pair;
export import stdlib.collections.Queue;
export import stdlib.collections.Set;
export import stdlib.collections.Stack;
export import stdlib.collections.Tuple;
export import stdlib.collections.UnorderedMap;
export import stdlib.collections.UnorderedSet;
export import stdlib.collections.ValArray;
export import stdlib.collections.Vector;
#endif

export using namespace stdlib;
