/**
 * @file DebugLogger.cppm
 * @brief Implementation of the DebugLogger class.
 *
 * This file contains the implementation of the DebugLogger class, which is used to log debug messages to a file.
 */

export module engine.utility.EngineUtility:DebugLogger;

#ifdef NO_RESERVED_STD
import std.core;
import std.fmt;
import std.fs;
import std.io;
import std.mem;
import std.util;
#else
import stdlib.core;
import stdlib.fmt;
import stdlib.fs;
import stdlib.io;
import stdlib.mem;
import stdlib.util;
#endif

import engine.utility.GameInfo;
import engine.utility.TimeFormat;

using io::IOS, io::IOSBaseException, io::OFStream, io::OStream, io::StringStream;
using mem::SharedPtr, mem::UniquePtr;

/**
 * @class DebugLogger
 * @brief Class for logging debug messages.
 *
 * @extends std::ostream (io::OStream)
 * 
 * The DebugLogger class is a singleton class that logs debug messages to a file.
 */
export class DebugLogger final: public OStream {
private:
    UniquePtr<OFStream> debugFile; ///< File stream for the debug log file.

    /**
     * @brief Private constructor to prevent instantiation.
     *
     * @throws IOSBaseException (std::ios_base::failure) if it fails to open debug.txt
     */
    DebugLogger():
        OStream(nullptr) {
        filesystem::create_directories(RuntimePaths::USERDATA_DIR);
        debugFile = mem::make_unique<OFStream>(RuntimePaths::PATH_DEBUGFILE, IOS::app);
        if (!debugFile->is_open()) {
            io::println(io::stderr, "Failed to open debug.txt!");
            throw IOSBaseException("Failed to open debug.txt.");
        }
        this->rdbuf(debugFile->rdbuf());
        filesystem::create_directories("userdata");
        
        OFStream file{RuntimePaths::PATH_DEBUGFILE, IOS::trunc};
        if (!file) {
            io::println(io::stderr, "Error opening file for emptying.");
        } else {
            this->log("==========BEGIN DEBUG LOG==========");
            this->log("Current time: {}", timeformat::getCurrentTimeAsString());
            this->log("===================================");
        }
    }
    
    /**
     * @brief Default destructor.
     */
    ~DebugLogger() = default;

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    DebugLogger(const DebugLogger&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    DebugLogger(DebugLogger&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    DebugLogger& operator=(const DebugLogger&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    DebugLogger& operator=(DebugLogger&&) = delete;
public:
    /**
     * @brief Get the singleton instance of DebugLogger.
     * @return The singleton instance.
     */
    static DebugLogger& getInstance() {
        static DebugLogger instance;
        return instance;
    }

    template<typename... Args>
    void log(const fmt::FormatString<Args...>& fmt, Args&&... args) {
        *this << fmt::format(fmt, util::forward<Args>(args)...) << '\n';
    }

    /**
     * @brief Log a message to the debug file.
     *
     * @tparam T The type of the message.
     * @param message The message to log.
     * @return Reference to the DebugLogger instance.
     */
    template<typename T>
    DebugLogger& operator<<(const T& message);

    /**
     * @brief Push a character to the debug file.
     *
     * @param message The message to log
     * @return Reference to the DebugLogger instance.
     */
    DebugLogger& operator<<(const String& c);

    /**
     * @brief Push a character to the debug file.
     *
     * @param c The character to push to logs
     * @return Reference to the DebugLogger instance.
     */
    DebugLogger& operator<<(char c);
};

template<typename T>
DebugLogger& DebugLogger::operator<<(const T& message) {
    if (debugFile && debugFile->is_open()) {
        StringStream ss;
        ss << message;
        debugFile->write(ss.str().c_str(), ss.str().size());
        debugFile->flush();
    }
    return *this;
}

DebugLogger& DebugLogger::operator<<(const String& message) {
    if (debugFile && debugFile->is_open()) {
        debugFile->write(message.c_str(), message.size()); 
        debugFile->flush();
    }
    return *this;
}

DebugLogger& DebugLogger::operator<<(char c) {
    if (debugFile && debugFile->is_open()) {
        debugFile->put(c); 
        debugFile->flush();
    }
    return *this;
}

/**
 * @namespace stdlib::io
 * @brief Wrapper namespace for standard library input/output operations.
 */
export namespace stdlib::io {
    /**
     * @brief Print to DebugLogger
     *
     * @tparam Args Types of arguments to format
     * @param logger The logger to print to
     * @param fmt Format string
     * @param args Arguments to format
     */
    template<typename... Args>
    void print(DebugLogger& logger, const fmt::FormatString<Args...>& fmt, Args&&... args) {
        logger << fmt::format(fmt, util::forward<Args>(args)...);
    }

    /**
     * @brief Print to DebugLogger with newline
     *
     * @tparam Args Types of arguments to format
     * @param logger The logger to print to
     * @param fmt Format string
     * @param args Arguments to format
     */
    template<typename... Args>
    void println(DebugLogger& logger, const fmt::FormatString<Args...>& fmt, Args&&... args) {
        logger << fmt::format(fmt, util::forward<Args>(args)...) << '\n';
    }
}