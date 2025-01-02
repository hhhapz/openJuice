#include "../../include/board/boards.hpp"

BoardLibrary::BoardLibrary() {
    loadBoards();
}

BoardLibrary& BoardLibrary::getInstance() {
    static BoardLibrary instance;
    return instance;
}

void BoardLibrary::loadBoards(const std::string& directory) {
    for (const auto& entry: std::filesystem::directory_iterator(directory)) {
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

const BoardInfo& BoardLibrary::getBoard(u32 id) const {
    return boardList[id - 1];
}