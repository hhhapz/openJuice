/**
 * @file GlobalSettings.cppm
 * @brief Implementation of the GlobalSettings class.
 *
 * This file contains the implementation of the GlobalSettings class, which manages global settings for the application.
 */

module;

#include <string>

export module engine.managers.GlobalSettings;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.sys;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.sys;
#endif

import engine.utility.Language;

using namespace stdlib::collections;

/**
 * @class GlobalSettings
 * @brief Class to manage global settings.
 * 
 * The GlobalSettings class is a singleton class that manages global settings for the application.
 */
export class GlobalSettings {
private:
    String programName; ///< The name of the executable.
    Vector<String> programArgs; ///< The program command line arguments.
    Language language; ///< The current language setting.
    f32 deltaTime; ///< The delta-time associated with the frame rate (1/frame rate)

    /**
     * @brief Private constructor to prevent instantiation.
     */
    GlobalSettings():
        language{Language::English} {}

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    GlobalSettings(const GlobalSettings&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    GlobalSettings& operator=(const GlobalSettings&) = delete;

public:
    /**
     * @brief Get the singleton instance of GlobalSettings.
     * @return The singleton instance.
     */
    static GlobalSettings& getInstance() {
        static GlobalSettings instance;
        return instance;
    }

    /**
     * @brief Get the singleton instance of GlobalSettings.
     * @return The singleton instance.
     */
    static String languageToString(Language lang) {
        switch (lang) {
            case Language::English:
                return "en";
            case Language::Japanese:
                return "jp";
            case Language::SimplifiedChinese:
                return "chs";
            case Language::TraditionalChinese:
                return "cht";
            case Language::Russian:
                return "ru";
            case Language::Korean:
                return "ko";
            case Language::Spanish:
                return "sp";
            case Language::PortugueseBR:
                return "ptbr";
            default:
                sys::unreachable();
        }
    }

    /**
     * @brief Set the program name.
     * @param name The name to set.
     */
    void setProgramName(String name) {
        programName = name;
    }

    /**
     * @brief Get the program name.
     * @return The program name.
     */
    String getProgramName() const {
        return programName;
    }

    /**
     * @brief Set the program arguments.
     * @param args The arguments of the program to set.
     */
    void setProgramArgs(Vector<String>& args) {
        programArgs = args;
    }

    /**
     * @brief Get the program arguments.
     * @return The program arguments.
     */
    Vector<String> getProgramArgs() const {
        return programArgs;
    }

    /**
     * @brief Set the language.
     * @param lang The language to set.
     */
    void setLanguage(Language lang) {
        language = lang;
    }

    /**
     * @brief Get the current language.
     * @return The current language.
     */
    Language getLanguage() const {
        return language;
    }

    /**
     * @brief Set the frame rate.
     * @param lang The frame rate to set.
     */
    void setFrameRate(u16 frameRate) {
        deltaTime = 1.0f / static_cast<f32>(frameRate);
    }

    /**
     * @brief Get the current deltaTime (1/frame rate).
     * @return The current deltaTime.
     */
    f32 getDeltaTime() const {
        return deltaTime;
    }
};