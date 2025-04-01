/**
 * @file RandomNumberGenerator.cppm
 * @brief Implementation of the RandomNumberGenerator class.
 *
 * This file contains the implementation of the RandomNumberGenerator class, which is used to generate random numbers.
 */

module;

#include <mutex>

export module engine.utility.RandomNumberGenerator;

#ifdef NO_RESERVED_STD
import std.core;
import std.math;
import std.concurrency;
#else
import stdlib.core;
import stdlib.math;
import stdlib.concurrency;
#endif

using namespace stdlib::concurrency;
using namespace stdlib::random;

/**
 * @class RandomNumberGenerator
 * @brief Class for generating random numbers.
 * 
 * The RandomNumberGenerator class is a singleton class that generates random numbers.
 */
export class RandomNumberGenerator final {
private:
    static MT19937 rng; ///< Mersenne Twister random number generator.
    static Mutex rng_mutex; ///< Mutex for thread-safe access to the RNG.

    /**
     * @brief Private constructor to prevent instantiation.
     */
    RandomNumberGenerator() = default;

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    RandomNumberGenerator(const RandomNumberGenerator&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    RandomNumberGenerator& operator=(const RandomNumberGenerator&) = delete;

public:
    /**
     * @brief Generate a random integer within a specified range.
     * @param min The minimum value.
     * @param max The maximum value.
     * @return A random integer between min and max.
     */
    static i32 getRandomInteger(i32 min, i32 max) {
        LockGuard<Mutex> lock(rng_mutex);
        UniformIntDistribution<i32> dist(min, max);
        return dist(rng);
    }

    /**
     * @brief Generate a random real number within a specified range.
     * @param min The minimum value.
     * @param max The maximum value.
     * @return A random real number between min and max.
     */
    static f64 getRandomReal(f64 min, f64 max) {
        LockGuard<Mutex> lock(rng_mutex);
        UniformRealDistribution<f64> dist(min, max);
        return dist(rng);
    }
};

MT19937 RandomNumberGenerator::rng(RandomDevice{}());
Mutex RandomNumberGenerator::rng_mutex;