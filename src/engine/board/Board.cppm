module;

#include <array>
#include <cassert>
#include <memory>
#include <print>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

#include <toml++/toml.hpp>

export module engine.board.Board;

import engine.board.Boards;
import engine.board.Panel;
import engine.utility.Utility;

static constexpr std::array<std::pair<i32, i32>, 4> directionOffsets = {{
    {-1,  0},  // Top
    { 0,  -1}, // Left     
    { 0,  1}, // Right
    { 1,  0} // Bottom
}};

using GameBoard = std::array<std::array<std::unique_ptr<Panel>, GameInfo::GAME_MAX_WIDTH>, GameInfo::GAME_MAX_HEIGHT>;

export class Board {
private:
    GameBoard gameBoard;
    std::array<std::pair<u8, u8>, GameInfo::MAX_PLAYERS> homePanels;
    u8 boardWidth;
    u8 boardHeight;
public:
    Board(u32 id) {
        const BoardInfo& boardData = BoardLibrary::getInstance().getBoard(id);
    }

    void printBoardASCII() const {
        std::println("█");
    }
};

class Graph {
private:
    std::unordered_map<std::shared_ptr<Panel>, std::vector<std::shared_ptr<Panel>>> adjList;
    std::unordered_map<std::shared_ptr<Panel>, std::vector<std::shared_ptr<Panel>>> reverseAdjList;

    void addEdge(std::shared_ptr<Panel> from, std::shared_ptr<Panel> to) {
        #ifdef DEBUG
        adjList.at(from).push_back(to);
        reverseAdjList.at(to).push_back(from);
        #else
        adjList[from].push_back(to);
        reverseAdjList[to].push_back(from);
        #endif
    }
public:
    Graph(const GameBoard& gameboard) {
        for (const auto& row: gameboard) {
            for (const auto& panel: row) {
                if (panel) {
                    for (usize i = 0; i < directionOffsets.size(); ++i) {
                        std::shared_ptr<Panel> neighbour = panel->getNeighbour(static_cast<Direction>(i));
                        if (neighbour)
                            addEdge(std::shared_ptr<Panel>(panel.get()), neighbour);
                    }
                }
            }
        }
    }

    std::vector<std::shared_ptr<Panel>> atDistance(std::shared_ptr<Panel> start, i32 n) const {
        std::vector<std::shared_ptr<Panel>> result;
        std::queue<std::pair<std::shared_ptr<Panel>, i32>> q;
        std::unordered_map<std::shared_ptr<Panel>, bool> visited;

        q.push({start, 0});
        #ifdef DEBUG
        visited.at(start) = true;
        #else
        visited[start] = true;
        #endif
        while (!q.empty()) {
            auto [current, distance] = q.front();
            q.pop();
            if (distance == n)
                result.push_back(current);
            const std::vector<std::shared_ptr<Panel>> neighbours = (n > 0) ? adjList.at(current) : reverseAdjList.at(current);
            for (const std::shared_ptr<Panel>& neighbour: neighbours) {
                #ifdef DEBUG
                if (!visited.at(neighbour))
                    visited.at(neighbour) = true;
                #else 
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                #endif
                    q.push({neighbour, distance + (n > 0 ? 1 : -1)});
                }
            }
        }
        return result;
    }
};