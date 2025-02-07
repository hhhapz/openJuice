module;

#include <array>
#include <filesystem>
#include <map>
#include <memory>
#include <string>

#include <toml++/toml.hpp>

export module engine.board.Boards;

import engine.utility.Utility;

export struct BoardInfo {
    u32 id;
    std::string boardName;
    u8 boardWidth;
    u8 boardHeight;
    std::array<std::pair<u8, u8>, GameInfo::MAX_PLAYERS> homePanels;
};

export class BoardLibrary {
private:
    BoardLibrary() {
        loadBoards();
    }

    BoardLibrary(const BoardLibrary&) = delete;
    BoardLibrary& operator=(const BoardLibrary&) = delete;
    std::vector<BoardInfo> boardList;
public:
    static BoardLibrary& getInstance() {
        static BoardLibrary instance;
        return instance;
    }

    void loadBoards(const std::string& directory = "./maps") {
        for (const std::filesystem::directory_entry& entry: std::filesystem::directory_iterator(directory)) {
            if (entry.is_regular_file() && entry.path().extension() == ".toml") {
                std::string boardPath = entry.path().string();
                toml::table data = toml::parse_file(boardPath);
    
                u32 id = *data["id"].value<u32>();
                std::string boardName = *data["name"].value<std::string>();
                u8 boardWidth = *data["width"].value<u8>();
                u8 boardHeight = *data["height"].value<u8>();
                std::array<std::pair<u8, u8>, GameInfo::MAX_PLAYERS> homePanels;
    
                const toml::array* homePanelsData = data["homePanels"].as_array();
                if (homePanelsData) {
                    for (usize i = 0; i < homePanelsData->size() && i < GameInfo::MAX_PLAYERS; ++i) {
                        const toml::array* panel = (*homePanelsData)[i].as_array();
                        if (panel && panel->size() == 2) {
                            homePanels[i] = {
                                static_cast<u8>((*panel)[0].value_or(0)),
                                static_cast<u8>((*panel)[1].value_or(0))
                            };
                        } else {
                            throw std::runtime_error("Invalid homePanels format!");
                        }
                    }
                } else {
                    throw std::runtime_error("homePanels is not a valid array!");
                }
    
                boardList.emplace_back(id, boardName, boardWidth, boardHeight, homePanels);
            }
        }
    }

    const BoardInfo& getBoard(u32 id) const {
        return boardList[id - 1];
    }
};