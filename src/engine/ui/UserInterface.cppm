/**
 * @file UserInterface.cppm
 * @brief Abstract interface for UI implementations
 */

export module engine.ui.UserInterface;

#ifdef NO_RESERVED_STD
import std.core;
import std.concurrency;
import std.mem;
#else
import stdlib.core;
import stdlib.concurrency;
import stdlib.mem;
#endif

import engine.game.Game;

using namespace stdlib::concurrency;
using stdlib::mem::SharedPtr;

/**
 * @class UserInterface
 * @brief Abstract base class for all user interfaces
 */
export class UserInterface {
protected:
    SharedPtr<Game> game;
    Mutex& stateMutex;
    AtomicBool exitRequested{false};
    
public:
    /**
     * @brief Construct a new User Interface object
     * 
     * @param game Shared pointer to the game instance
     * @param mutex Reference to mutex for thread-safe access
     */
    UserInterface(SharedPtr<Game> game, Mutex& mutex): 
        game{game}, stateMutex{mutex} {}
    
    virtual ~UserInterface() = default;
    
    virtual void init() = 0;
    virtual void processEvents() = 0;
    virtual void render() = 0;
    
    bool shouldExit() const {
        return exitRequested.load();
    }
    
    void requestExit() {
        exitRequested.store(true);
    }
};