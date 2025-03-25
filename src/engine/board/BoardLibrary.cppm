/**
 * @file BoardLibrary.cppm
 * @brief Implementation of the BoardLibrary class.
 *
 * This file contains the implementation of the BoardLibrary class, which is used to load and manage boards.
 */

module;

#include <filesystem>

export module engine.board.BoardLibrary;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.io;
import std.fmt;
import std.fs;
import std.mem;
import std.sys;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.io;
import stdlib.fmt;
import stdlib.fs;
import stdlib.mem;
import stdlib.sys;
#endif

import engine.board.BoardInfo;
import engine.managers.GlobalSettings;
import engine.utility.EngineUtility;
import engine.utility.GameInfo;

import tomlpp;

using namespace collections;
using filesystem::FileSystemException;
using mem::SharedPtr;

/**
 * @class BoardLibrary
 * @brief Singleton class for loading and managing boards.
 * 
 * The BoardLibrary class is a singleton class that loads and manages boards from files.
 */
export class BoardLibrary {
private:
    /**
     * @brief Private constructor to prevent instantiation.
     */
    BoardLibrary() {
        loadBoards();
    }

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    BoardLibrary(const BoardLibrary&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    BoardLibrary& operator=(const BoardLibrary&) = delete;

    Vector<SharedPtr<BoardInfo>> boardList; ///< List of loaded boards.
public:
    /**
     * @brief Get the singleton instance of BoardLibrary.
     * @return The singleton instance.
     */
    static BoardLibrary& getInstance() {
        static BoardLibrary instance;
        return instance;
    }

    /**
     * @brief Load boards into the boardList.
     * @param directory (Optional) The directory to load maps from.
     * @throws FileSystemException (std::filesystem::filesystem_error) if there is any error loading the directory
     * @throws RuntimeException (std::runtime_error) if there is any error parsing the TOML file
     * @throws toml::ParseError (toml::parse_error)
     */
    void loadBoards(const String& directory = RuntimePaths::MAPS_DIR) {
        DebugLogger::getInstance().log("Loading boards from directory: {}", directory);
        if (!filesystem::exists(directory))
            throw FileSystemException("Failed to load directory", directory, sys::make_error_code(sys::ErrC::no_such_file_or_directory));
        for (const filesystem::DirectoryEntry& entry: filesystem::DirectoryIterator(directory)) {
            if (entry.is_regular_file() && entry.path().extension() == ".toml") {
                String boardPath = entry.path().string();
                toml::Table data = toml::parse_file(boardPath);
    
                u32 id = *data["id"].value<u32>();
                String boardName = *data["name"].value<String>();
                u8 boardWidth = *data["width"].value<u8>();
                u8 boardHeight = *data["height"].value<u8>();
                Array<Pair<u8, u8>, GameInfo::MAX_PLAYERS> homePanels;
    
                const toml::Array* homePanelsData = data["homePanels"].as_array();
                if (homePanelsData) {
                    for (usize i = 0; i < homePanelsData->size() && i < GameInfo::MAX_PLAYERS; ++i) {
                        const toml::Array* panel = (*homePanelsData)[i].as_array();
                        if (panel && panel->size() == 2) {
                            homePanels[i] = {
                                static_cast<u8>((*panel)[0].value_or(0)),
                                static_cast<u8>((*panel)[1].value_or(0))
                            };
                        } else {
                            throw RuntimeException("Invalid homePanels format!");
                        }
                    }
                } else {
                    throw RuntimeException("homePanels is not a valid array!");
                }
    
                boardList.push_back(mem::make_shared<BoardInfo>(id, boardName, boardWidth, boardHeight, homePanels));
            }
        }
    }

    /**
     * @brief Get the board information for a given ID.
     * @param id The ID of the board (0 returns nullptr, representing no board).
     * @return SharedPtr to board information (nullptr if id is 0)
     */
    SharedPtr<BoardInfo> getBoard(u32 id) const {
        DebugLogger::getInstance().log("Returning board ID: {}", id);
        if (id == 0)
            return nullptr;
        #ifndef NDEBUG
        return boardList.at(id - 1);
        #else
        return boardList[id - 1];
        #endif
    }

    /**
     * @brief Access board information by ID using array syntax.
     * @param id The ID of the board (0 returns nullptr, representing no board).
     * @return SharedPtr to board information (nullptr if id is 0)
     */
    SharedPtr<BoardInfo> operator[](u32 id) const {
        return getBoard(id);
    }
};