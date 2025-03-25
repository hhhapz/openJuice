/**
 * @file Primitives.cppm
 * @brief Module file for custom-defined primitive types.
 * 
 * This file contains the implementation of custom-defined primitive types.
 */

module;

#include <cstdint>

#ifdef __GNUC__
#include <stdfloat>
#endif

#ifdef NO_RESERVED_STD
export module std.core.Primitives;
#else
export module stdlib.core.Primitives;
#endif

/**
 * @namespace stdlib
 * @brief Wrapper namespace for the standard library.
 */
export namespace stdlib {
    using i8 = int8_t;
    using i16 = int16_t;
    using i32 = int32_t;
    using i64 = int64_t;
    using u8 = uint8_t;
    using u16 = uint16_t;
    using u32 = uint32_t;
    using u64 = uint64_t;
    // using f16 = std::float16_t;
    // using f32 = std::float32_t;
    // using f64 = std::float64_t;
    // using f128 = std::float128_t;
    // using bf16 = std::bfloat16_t;
    using f32 = float;
    using f64 = double;
    using usize = std::size_t;
}