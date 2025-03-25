/**
 * @file InputParser.cppm
 * @brief Implementation of the InputParser class.
 *
 * This file contains the implementation of the InputParser class, which extends the InputParserBase class to handle specific command line options.
 */

module;

#include <cassert>
#include <print>

export module engine.utility.inputparser.InputParser;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.fmt;
import std.io;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.fmt;
import stdlib.io;
#endif

import engine.managers.GlobalSettings;
import engine.utility.EngineUtility;
import engine.utility.Messages;
import engine.utility.inputparser.InputParserBase;

using namespace collections;

/**
 * @class InputParser
 * @brief Class for parsing and handling specific command line options.
 *
 * @extends InputParserBase
 * 
 * The InputParser class extends the InputParserBase class to handle specific command line options.
 */
export class InputParser final: private InputParserBase {
private:
    static const Vector<String> validOptions; ///< Vector of valid command line options.
public:
    /**
     * @brief Constructor that initialises the parser with command line arguments.
     * @param argc Number of command line arguments.
     * @param argv Array of command line arguments.
     * @param envp Array of environment variable arguments.
     */
    InputParser(i32 argc, char* argv[], char* envp[] = nullptr):
        InputParserBase(argc, argv, envp, validOptions) {}

    /**
     * @brief Constructor that initialises the parser with command line arguments.
     * @param argc Number of command line arguments.
     * @param argv Array of command line arguments.
     * @param envp Array of environment variable arguments.
     */
     InputParser(Vector<String>& args, char* envp[] = nullptr):
     InputParserBase(args, envp, validOptions) {}

    /**
     * @brief Handle the parsed command line inputs.
     * @return An integer indicating the result of handling the inputs.
     */
    i8 handleInputs() {
        if (optionExists("-h")) {
            messages::printHelp();
            return -1;
        } else if (optionExists("-v")) {
            messages::printCredits();
            return -1;
        }

        if (optionExists("-c")) {
            return 1;
        }

        return 0;
    }
};

const Vector<String> InputParser::validOptions = {
    "-h", // Print help
    "-v", // Print version + credits
    "-c"  // Custom option
};