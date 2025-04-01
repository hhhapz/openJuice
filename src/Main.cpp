/**
 * @file Main.cpp
 * @brief Entry point for the openJuice application.
 *
 * This file contains the main function of the openJuice application.
 */

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.io;
import std.sys;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.io;
import stdlib.sys;
#endif

import engine.game.Engine;
import engine.managers.GlobalSettings;
import engine.utility.EngineUtility;
import engine.utility.inputparser.InputParser;

using namespace stdlib::collections;

/**
 * @class Main
 * @brief Utility Main class to directly handle args as a vector
 */
class Main {
private:
    /**
     * @brief Private constructor to prevent instantiation.
     */
    Main() = default;

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    Main(const Main&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    Main& operator=(const Main&) = delete;
public:
    /**
     * @brief The main function of the openJuice application.
     *
     * @param args Vector of command line arguments
     * @throws RuntimeException (std::runtime_error), should never happen
     */
    static void main(Vector<String>& args) {
        LaunchMode lm;
        InputParser inputs(args);
        switch (inputs.handleInputs()) {
            case -1:
                // -1: Help message or version message was called
                return;
            case 0:
                // 0: Game runs in TUI mode
                lm = LaunchMode::TUI;
                break;
            case 1:
                // 1: Game runs in CLI mode
                lm = LaunchMode::CLI;
                break;
            default:
                // This should never happen
                throw RuntimeException("Invalid command line arguments state.");
        }
        Engine eng(lm);
        eng.init();
    }
};

/**
 * @brief The main function of the openJuice application.
 *
 * @param argc Number of command line arguments
 * @param argv Command line arguments
 * @return Exit code
 */
int main(int argc, char* argv[]) {
    try {
        GlobalSettings::getInstance().setProgramName(argv[0]);
        Vector<String> args(argv + 1, argv + argc);
        GlobalSettings::getInstance().setProgramArgs(args);
        Main::main(args);
    } catch (const Exception& e) {
        DebugLogger::getInstance().log("An error occured: {}", e.what());
        return 1;
    } catch (...) {
        DebugLogger::getInstance().log("An unknown error occured.");
        return -1;
    }
    return 0;
}
