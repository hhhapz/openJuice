/**
 * @file math.cppm
 * @brief Module file for standard library mathematical operations.
 *
 * This file contains the imports for the mathematical operations in the standard library.
 */

module;

#include <cstddef>

#ifdef NO_RESERVED_STD
export module std.math;
#else
export module stdlib.math;
#endif

#ifdef NO_RESERVED_STD
import std.core.CStdDef;
#else
import stdlib.core.CStdDef;
#endif

#ifdef NO_RESERVED_STD
export import std.math.Bit;
export import std.math.CMath;
export import std.math.Complex;
export import std.math.Numbers;
export import std.math.Numeric;
export import std.math.Random;
export import std.math.Ratio;
#else
export import stdlib.math.Bit;
export import stdlib.math.CMath;
export import stdlib.math.Complex;
export import stdlib.math.Numbers;
export import stdlib.math.Numeric;
export import stdlib.math.Random;
export import stdlib.math.Ratio;
#endif

/**
 * @brief Wrapper namespace for standard library mathematical operations.
 */
export namespace stdlib::math {
    using std::to_integer;
}

export using namespace stdlib;
