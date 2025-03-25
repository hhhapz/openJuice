/**
 * @file ProfileManager.cppm
 * @brief Implementation of the ProfileManager class.
 *
 * This file contains the implementation of the ProfileManager class, which manages the current profile for the application.
 */

export module engine.managers.ProfileManager;

#ifdef NO_RESERVED_STD
import std.core;
import std.io;
import std.fs;
import std.sys;
#else
import stdlib.core;
import stdlib.io;
import stdlib.fs;
import stdlib.sys;
#endif

import engine.managers.GlobalSettings;
import engine.utility.EngineUtility;
import engine.utility.GameInfo;

import tomlpp;

using io::OFStream;

/**
 * @struct ProfileData
 * @brief Struct to store profile data across the game.
 */
struct ProfileData {
    String playerName; ///< The player name
    u64 totalPlayTime; ///< The total amount of time played in the save slot, in seconds
};

/**
 * @class ProfileManager
 * @brief Class to manage global settings.
 * 
 * The ProfileManager class is a singleton class that manages profile information for the application.
 */
export class ProfileManager {
private:
    ProfileData currentProfile; ///< The information of the current save file.
    bool profileLoaded = false; ///< Whether the profile has been loaded by the game yet.

    /**
     * @brief Private constructor to prevent instantiation.
     */
    ProfileManager() {
        try {
            filesystem::create_directories(RuntimePaths::USERDATA_DIR);
            loadProfile();
        } catch (const Exception& e) {
            DebugLogger::getInstance().log("Failed to initialise ProfileManager: {}", e.what());
        }
    }

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
     ProfileManager(const ProfileManager&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
     ProfileManager& operator=(const ProfileManager&) = delete;

public:    
    /**
     * @brief Get the singleton instance of ProfileManager.
     * @return The singleton instance.
     */
    static ProfileManager& getInstance() {
        static ProfileManager instance;
        return instance;
    }

    /**
     * @brief Load profile data from file.
     * @return True if successfully loaded, false otherwise.
     */
    bool loadProfile() {
        try {
            if (!filesystem::exists(RuntimePaths::PATH_SAVEFILE)) {
                DebugLogger::getInstance().log("Save file not found, creating new profile");
                return saveProfile();
            }

            profileLoaded = true;
            DebugLogger::getInstance().log("Profile loaded successfully for {}", currentProfile.playerName);
            return true;
        } catch (const Exception& e) {
            DebugLogger::getInstance().log("Error loading profile: {}", e.what());
            return false;
        }
    }

    /**
     * @brief Save profile data to file.
     * @return True if successfully saved, false otherwise.
     */
    bool saveProfile() {
        try {
            toml::Table data;

            OFStream file{RuntimePaths::PATH_SAVEFILE};
            file << data;
            file.close();

            DebugLogger::getInstance().log("Profile saved successfully for {}", currentProfile.playerName);
            return true;
        } catch (const Exception& e) {
            DebugLogger::getInstance().log("Error saving profile: {}", e.what());
            return false;
        }
    }

    /**
     * @brief Reset profile data (start new game)
     * @return True if successfully reset, false otherwise.
     */
    bool resetProfile() {
        try {
            DebugLogger::getInstance().log("Attempting to reset profile for {}", currentProfile.playerName);
            return saveProfile();
        } catch (const Exception& e) {
            DebugLogger::getInstance().log("Error resetting profile: {}", e.what());
            return false;
        }
    }
};