module;

#include <algorithm>
#include <cassert>
#include <string>
#include <stdexcept>
#include <vector>

export module utility.InputParser;

import utility.Utility;

bool isInteger(const std::string& s) {
    try {
        std::stoi(s);
        return true;
    } catch (...) {
        return false;
    }
}

export class InputParser {
private:
    std::vector<std::string> args;
    std::vector<std::string> validOptions; // Optional
public:
    // Constructor
    InputParser(i32 argc, char* argv[]) {
        for (i32 i = 1; i < argc; ++i) 
            args.push_back(std::string(argv[i]));
    }
    InputParser(i32 argc, char* argv[], const std::vector<std::string>& validOptions): 
        validOptions(validOptions) {
        #ifdef DEBUG
        assert(argc >= 1);
        #endif
        bool foundValue = false;
        for (i32 i = 1; i < argc; ++i) 
            args.push_back(std::string(argv[i]));
        for (const std::string& arg: args) {
            if (std::find(validOptions.begin(), validOptions.end(), arg) == validOptions.end()) {
                if (isInteger(arg) && !foundValue) {
                    foundValue = true;
                    continue;
                }
                throw std::invalid_argument("Invalid option: " + arg);
            }
        }
    }

    // Methods
    std::string getOptionValue(const std::string& option) const {
        std::vector<std::string>::const_iterator it = std::find(args.begin(), args.end(), option);
        if (it != args.end() && ++it != args.end()) 
            return *it;
        return "";
    }
    bool optionExists(const std::string& option) const {
        return std::find(args.begin(), args.end(), option) != args.end();
    }
};