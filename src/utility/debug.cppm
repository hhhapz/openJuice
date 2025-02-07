module;

#include <fstream>
#include <string>
#include <memory>
#include <print>

export module utility.Debug;

class Debug: public std::ostream {
private:
    std::unique_ptr<std::ofstream> debugFile;
    Debug():
        debugFile(std::make_unique<std::ofstream>("debug.txt", std::ios::app)) {
        if (!debugFile->is_open())
            std::println("Failed to open debug.txt!");
    }
    ~Debug() = default;
    Debug(const Debug&) = delete;
    Debug(Debug&&) = delete;
    Debug& operator=(const Debug&) = delete;
    Debug& operator=(Debug&&) = delete;
public:
    // Methods
    static Debug& getInstance() {
        static Debug instance;
        return instance;
    }
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
