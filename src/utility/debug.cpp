#include "../../include/utility/debug.hpp"

Debug::Debug():
    debugFile(std::make_unique<std::ofstream>("debug.txt", std::ios::app)) {
    if (!debugFile->is_open())
        std::println("Failed to open debug.txt!");
}

Debug& Debug::getInstance() {
    static Debug instance;
    return instance;
}