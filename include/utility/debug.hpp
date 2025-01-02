#pragma once

#include <fstream>
#include <string>
#include <memory>
#include <print>

class Debug: public std::ostream {
private:
    std::unique_ptr<std::ofstream> debugFile;
    Debug();
    ~Debug() = default;
    Debug(const Debug&) = delete;
    Debug(Debug&&) = delete;
    Debug& operator=(const Debug&) = delete;
    Debug& operator=(Debug&&) = delete;
public:
    // Methods
    static Debug& getInstance();
    template<typename T>
    Debug& operator<<(const T& message);
};

template<typename T>
Debug& Debug::operator<<(const T& message) {
    if (debugFile && debugFile->is_open()) {
        *debugFile << message;
        debugFile->flush();
    }
    return *this;
}
