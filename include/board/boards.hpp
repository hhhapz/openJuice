#pragma once
#include <array>
#include <filesystem>
#include <map>
#include <memory>
#include <string>

#include <toml++/toml.hpp>

#include "../utility/stdint.hpp"

struct BoardInfo {
    u32 id;
    std::string boardName;
    u8 boardWidth;
    u8 boardHeight;
    std::array<std::pair<u8, u8>, GameInfo::MAX_PLAYERS> homePanels;
};

class BoardLibrary {
private:
    BoardLibrary() = default;
    BoardLibrary(const BoardLibrary&) = delete;
    BoardLibrary& operator=(const BoardLibrary&) = delete;
    std::map<u32, BoardInfo> boardMap;
public:
    static BoardLibrary& getInstance();
    void loadBoards(const std::string& directory = "./maps");
};