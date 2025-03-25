/**
 * @file Random.cppm
 * @brief Module file for standard library random number operations.
 *
 * This file contains the implementation of the random number operations in the standard library.
 */

module;

#include <random>

#ifdef NO_RESERVED_STD
export module std.math.Random;
#else
export module stdlib.math.Random;
#endif

/**
 * @namespace stdlib::random
 * @brief Wrapper namespace for standard library random number operations.
 */
export namespace stdlib::random {
    // Predefined Generators
    using MinStdRand0 = std::minstd_rand0;
    using MinStdRand = std::minstd_rand;
    using MT19937 = std::mt19937;
    using MT19937_64 = std::mt19937_64;
    using Ranlux24Base = std::ranlux24_base;
    using Ranlux48Base = std::ranlux48_base;
    using Ranlux24 = std::ranlux24;
    using Ranlux48 = std::ranlux48;
    using KnuthB = std::knuth_b;

    // Non-deterministic random numbers
    using RandomDevice = std::random_device;

    // Distributions
    template<typename T>
    using UniformIntDistribution = std::uniform_int_distribution<T>;

    template<typename T>
    using UniformRealDistribution = std::uniform_real_distribution<T>;

    // Seed sequence
    using SeedSeq = std::seed_seq;
}
