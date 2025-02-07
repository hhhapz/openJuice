module;

#include <mutex>
#include <random>

export module engine.utility.Random;

import engine.utility.Utility;

export class Random {
private:
    static std::mt19937 rng;
    static std::mutex rng_mutex;

    static i32 getRandomNumber(i32 min, i32 max) {
        std::lock_guard<std::mutex> lock(rng_mutex);
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }
public:
    static u8 rollD6() {
        return static_cast<u8>(getRandomNumber(1, 6));
    }

    static u8 rollD8() {
        return static_cast<u8>(getRandomNumber(0, 7));
    }
};

std::mt19937 Random::rng(std::random_device{}());
std::mutex Random::rng_mutex;