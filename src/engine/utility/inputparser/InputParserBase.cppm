/**
 * @file InputParserBase.cppm
 * @brief Definition of the InputParserBase class.
 *
 * This file contains the definition of the InputParserBase class, which is used to parse command line input.
 */

module;

#include <algorithm>
#include <cassert>
#include <string>

export module engine.utility.inputparser.InputParserBase;

#ifdef NO_RESERVED_STD
import std.algorithm;
import std.core;
import std.collections;
import std.fmt;
import std.io;
import std.text;
#else
import stdlib.algorithm;
import stdlib.core;
import stdlib.collections;
import stdlib.fmt;
import stdlib.io;
import stdlib.text;
#endif

using namespace stdlib::collections;

/**
 * @brief Checks if a string represents an integer.
 * @param s The string to check.
 * @return true if the string represents an integer, false otherwise.
 */
bool isInteger(const String& s) {
    try {
        string::stoi(s);
        return true;
    } catch (...) {
        return false;
    }
}

/**
 * @class InputParserBase
 * @brief Class for parsing command line input.
 */
export class InputParserBase {
private:
    Vector<String> args; ///< Vector of command line arguments.
    Vector<String> envs; ///< Vector of environment variables.

public:
    /**
     * @brief Constructor that initialises the parser with command line arguments.
     * @param argc Number of command line arguments.
     * @param argv Array of command line arguments.
     * @param envp Array of environment variable arguments.
     */
    InputParserBase(i32 argc, char* argv[], char* envp[] = nullptr):
        args{Vector<String>(argv + 1, argv + argc)} {
        if (envp)
            for (char** env = envp; *env != nullptr; ++env)
                envs.push_back(String(*env));
    }

    /**
     * @brief Constructor that initialises the parser with command line arguments.
     * @param args Vector of command line arguments
     * @param envp Array of environment variable arguments.
     */
     InputParserBase(Vector<String>& args, char* envp[] = nullptr): 
        args{args} {
        if (envp)
            for (char** env = envp; *env != nullptr; ++env)
                envs.push_back(String(*env));
    }

    /**
     * @brief Constructor that initializes the parser with command line arguments and valid options.
     * @param argc Number of command line arguments.
     * @param argv Array of command line arguments.
     * @param envp Array of environment variable arguments.
     * @param validOptions Vector of valid options.
     * @throws InvalidArgumentException (std::invalid_argument) if an invalid argument is found
     */
    InputParserBase(i32 argc, char* argv[], char* envp[] = nullptr, const Vector<String>& validOptions = {}) {
        assert(argc >= 1);
        assert(argv);
        bool foundValue = false;
        for (i32 i = 1; i < argc; ++i) 
            args.push_back(String(argv[i]));
        if (envp)
            for (char** env = envp; *env != nullptr; ++env)
                envs.push_back(*env);
        for (const String& arg: args) {
            if (algorithm::find(validOptions.begin(), validOptions.end(), arg) == validOptions.end()) {
                if (isInteger(arg) && !foundValue) {
                    foundValue = true;
                    continue;
                }
                throw InvalidArgumentException(fmt::format("Invalid option: {}", arg));
            }
        }
    }

    /**
     * @brief Constructor that initializes the parser with command line arguments and valid options.
     * @param args Vector of command line arguments.
     * @param envp Array of environment variable arguments.
     * @param validOptions Vector of valid options.
     * @throws InvalidArgumentException (std::invalid_argument) if an invalid argument is found
     */
     InputParserBase(Vector<String>& args, char* envp[] = nullptr, const Vector<String>& validOptions = {}): 
        args{args} {
        bool foundValue = false;
        if (envp)
            for (char** env = envp; *env != nullptr; ++env)
                envs.push_back(*env);
        for (const String& arg: args) {
            if (algorithm::find(validOptions.begin(), validOptions.end(), arg) == validOptions.end()) {
                if (isInteger(arg) && !foundValue) {
                    foundValue = true;
                    continue;
                }
                throw InvalidArgumentException(fmt::format("Invalid option: {}", arg));
            }
        }
    }

    /**
     * @brief Gets the value of a specified option.
     * @param option The option to get the value for.
     * @return The value of the option, or an empty string if the option does not exist.
     */
    String getOptionValue(const String& option) const {
        Vector<String>::const_iterator it = algorithm::find(args.begin(), args.end(), option);
        if (it != args.end() && ++it != args.end()) 
            return *it;
        return "";
    }
    
    /**
     * @brief Checks if a specified option exists.
     * @param option The option to check for.
     * @return true if the option exists, false otherwise.
     */
    bool optionExists(const String& option) const {
        return algorithm::find(args.begin(), args.end(), option) != args.end();
    }  
};