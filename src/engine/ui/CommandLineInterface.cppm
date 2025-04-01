/**
 * @file CommandLineInterface.cppm
 * @brief Command line interface implementation
 */

export module engine.ui.CommandLineInterface;

#ifdef NO_RESERVED_STD
import std.core;
import std.concurrency;
import std.io;
import std.mem;
#else
import stdlib.core;
import stdlib.concurrency;
import stdlib.io;
import stdlib.mem;
#endif

import engine.game.Game;
import engine.ui.cli.CLIUtils;
import engine.ui.UserInterface;

using namespace stdlib::concurrency;
using stdlib::mem::SharedPtr;

/**
 * @class CommandLineInterface
 * @brief 
 *
 * @extends UserInterface
 */
export class CommandLineInterface: public UserInterface {
private:
    /**
     * @brief 
     * 
     * @return true if there is input, false otherwise
     */
    bool hasInput() {
        return false;
    }
    
    /**
     * @brief 
     * 
     * @return String 
     */
    String readInput() {
        return "";
    }
    
    /**
     * @brief 
     * 
     * @param cmd 
     */
    void processCommand(const String& cmd) {
        return;
    }
public:
    /**
     * @brief Constructor that initialises the base UserInterface
     * @param state Shared pointer to game instance
     * @param mutex Reference to state mutex for synchronisation
     */
    CommandLineInterface(SharedPtr<Game> game, Mutex& mutex): 
        UserInterface(game, mutex) {}

    /**
     * @brief 
     */
    void init() override {
        cliutils::initialiseLanguage();
        cliutils::initialiseFrameRate();
    }
    
    /**
     * @brief 
     */
    void processEvents() override {
        if (hasInput()) {
            String command = readInput();
            
            if (command == "exit") {
                requestExit();
            } else {
                LockGuard<Mutex> lock(stateMutex);
                processCommand(command);
            }
        }
    }
    
    /**
     * @brief 
     */
    void render() override {
        io::println("Current game state: {}", game->toString());
    }
};