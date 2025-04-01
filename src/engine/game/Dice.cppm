/**
 * @file Dice.cppm
 * @brief Thread-safe singleton dice system with roll history using RAII.
 */

module;

#include <mutex>

export module engine.game.Dice;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.concurrency;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.concurrency;
#endif

import engine.utility.GameInfo;
import engine.utility.RandomNumberGenerator;

using namespace stdlib::collections;
using namespace stdlib::concurrency;

/**
 * @class Dice
 * @brief Thread-safe singleton class for dice rolling with history tracking
 */
export class Dice {
private:
    /**
     * @struct RollRecord
     * @brief Contains information on the number of sides rolled by the dice and the result.
     */
    struct RollRecord {
        u8 sides; 
        u8 result; 
        
        RollRecord(u8 sides, u8 result): 
            sides{sides}, result{result} {}
    };
    
    Deque<RollRecord> rollHistory; ///< The history of all dice rolls
    mutable Mutex historyMutex; /// A mutex for the dice roll history
    
    Dice() = default;
    Dice(const Dice&) = delete;
    Dice& operator=(const Dice&) = delete;
    Dice(Dice&&) = delete;
    Dice& operator=(Dice&&) = delete;
    
    void recordRoll(u8 sides, u8 result) {
        LockGuard<Mutex> lock(historyMutex);
        rollHistory.push_back(RollRecord(sides, result));
        if (rollHistory.size() > GameInfo::MAX_DICEROLL_HISTORY_SIZE)
            rollHistory.pop_front();
    }
    
public:
    
    /**
     * @brief Get the singleton instance (thread-safe using Meyer's singleton)
     * @return Reference to the singleton Dice instance
     */
    static Dice& getInstance() {
        static Dice instance;
        return instance;
    }
    
    /**
     * @brief Roll a 6-sided die
     * @return A random number between 1 and 6
     */
    u8 rollD6() {
        u8 result = static_cast<u8>(RandomNumberGenerator::getRandomInteger(1, 6));
        recordRoll(6, result);
        return result;
    }
    
    /**
     * @brief Roll an 8-sided die
     * @return A random number between 0 and 7
     */
    u8 rollD8() {
        u8 result = static_cast<u8>(RandomNumberGenerator::getRandomInteger(0, 7));
        recordRoll(8, result);
        return result;
    }
    
    /**
     * @brief Get the roll history (thread-safe)
     * @return Vector of roll records (sides, result)
     */
    Vector<Pair<u8, u8>> getHistory() const {
        LockGuard<Mutex> lock(historyMutex);
        Vector<Pair<u8, u8>> history;
        history.reserve(rollHistory.size());
        
        for (const RollRecord& record: rollHistory)
            history.emplace_back(record.sides, record.result);
        
        return history;
    }
    
    /**
     * @brief Get statistics for a specific die
     * @param sides Number of sides on the die
     * @return Pair of (total rolls, average result)
     */
    Pair<usize, f32> getStats(u8 sides) const {
        LockGuard<Mutex> lock(historyMutex);
        usize count = 0;
        f32 sum = 0.0f;
        
        for (const RollRecord& record: rollHistory) {
            if (record.sides == sides) {
                ++count;
                sum += record.result;
            }
        }
        
        return {count, count > 0 ? sum / count : 0.0f};
    }
    
    /**
     * @brief Clear the roll history
     */
    void clearHistory() {
        LockGuard<Mutex> lock(historyMutex);
        rollHistory.clear();
    }
};