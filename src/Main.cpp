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

using namespace collections;

/**
 * @brief The main function of the openJuice application.
 *
 * @param argc Number of command line arguments
 * @param argv Command line arguments
 * @return Exit code
 * @throws RuntimeException (std::runtime_error), should never happen
 */
int main(int argc, char* argv[]) {
    LaunchMode lm;
    GlobalSettings::getInstance().setProgramName(argv[0]);
    Vector<String> args(argv + 1, argv + argc);
    InputParser inputs(args);
    try {
        switch (inputs.handleInputs()) {
            case -1:
                // -1: Help message or version message was called
                return 0;
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
    } catch (const Exception& e) {
        DebugLogger::getInstance().log("An error occured: {}", e.what());
        return 1;
    } catch (...) {
        DebugLogger::getInstance().log("An unknown error occured.");
        return -1;
    }
    return 0;
}
