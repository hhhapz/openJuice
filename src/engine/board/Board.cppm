/**
 * @file Board.cppm
 * @brief Implementation of the Board class.
 *
 * This file contains the implementation of the Board class, which represents the game board and its state.
 */

module;

#include <cassert>
#include <memory>

export module engine.board.Board;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.io;
import std.mem;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.io;
import stdlib.mem;
#endif

import engine.board.BoardInfo;
import engine.board.BoardLibrary;
import engine.board.Panel;
import engine.utility.Colours;
import engine.utility.GameInfo;

using namespace collections;
using mem::SharedPtr, mem::UniquePtr;

/**
 * @brief Direction offsets
 *
 * This array defines the offsets for the four cardinal directions (top, left, right, bottom).
 */
static constexpr Array<Pair<i32, i32>, 4> directionOffsets = {{
    {-1,  0}, // Top
    { 0, -1}, // Left
    { 0,  1}, // Right
    { 1,  0}  // Bottom
}};

export using GameBoard = Array<Array<UniquePtr<Panel>, GameInfo::GAME_MAX_WIDTH>, GameInfo::GAME_MAX_HEIGHT>;

/**
 * @class Board
 * @brief Class representing the game board.
 *
 * The Board class represents the game board and its state, including the panels and their connections.
 */
export class Board {
private:
    GameBoard gameBoard; ///< The game board represented as a 2D array of panels.
    Array<Pair<u8, u8>, GameInfo::MAX_PLAYERS> homePanels; ///< The home panels for each player.
    u8 boardWidth; ///< The width of the board.
    u8 boardHeight; ///< The height of the board.
public:
    /**
     * @brief Construct a new Board object.
     *
     * @param id The ID of the Board to construct.
     */
    Board(u32 id) {
        SharedPtr<BoardInfo> boardData = BoardLibrary::getInstance()[id];
        if (boardData) {
            boardWidth = boardData->boardWidth;
            boardHeight = boardData->boardHeight;
            homePanels = boardData->homePanels;
        } else {
            boardWidth = 0;
            boardHeight = 0;
        }
    }

    /**
     * @brief Print the board to the terminal.
     */
    void printBoardASCII() const {
        io::println("█");
    }
};

/**
 * @class Graph
 * @brief Class representing a graph for internal calculations.
 *
 * The Graph class is used to handle calculations internally, such as finding paths and distances between panels.
 */
class Graph {
private:
    UnorderedMap<SharedPtr<Panel>, Vector<SharedPtr<Panel>>> adjList; ///< Adjacency list for the graph.
    UnorderedMap<SharedPtr<Panel>, Vector<SharedPtr<Panel>>> reverseAdjList; ///< Reverse adjacency list for the graph.

    /**
     * @brief Adds an edge to the Graph.
     *
     * @param from The Panel from which the edge originates.
     * @param to The Panel to which the edge leads.
     */
    void addEdge(SharedPtr<Panel> from, SharedPtr<Panel> to) {
        #ifndef NDEBUG
        adjList.at(from).push_back(to);
        reverseAdjList.at(to).push_back(from);
        #else
        adjList[from].push_back(to);
        reverseAdjList[to].push_back(from);
        #endif
    }
public:
    /**
     * @brief Construct a new Graph object.
     *
     * @param gameboard The GameBoard to initialise the Graph with.
     */
    Graph(const GameBoard& gameboard) {
        for (const Array<UniquePtr<Panel>, GameInfo::GAME_MAX_WIDTH>& row: gameboard) {
            for (const UniquePtr<Panel>& panel: row) {
                if (panel) {
                    for (usize i = 0; i < directionOffsets.size(); ++i) {
                        SharedPtr<Panel> neighbour = panel->getNeighbour(static_cast<Direction>(i));
                        if (neighbour)
                            addEdge(SharedPtr<Panel>(panel.get()), neighbour);
                    }
                }
            }
        }
    }

    /**
     * @brief Finds all panels a distance of n panels away.
     *
     * @param start The starting panel.
     * @param n The number of panels to search away from start.
     * @return Vector<SharedPtr<Panel>> The panels at the specified distance.
     */
    Vector<SharedPtr<Panel>> atDistance(SharedPtr<Panel> start, i32 n) const {
        Vector<SharedPtr<Panel>> result;
        Queue<Pair<SharedPtr<Panel>, i32>> q;
        UnorderedMap<SharedPtr<Panel>, bool> visited;

        q.push({start, 0});

        #ifndef NDEBUG
        visited.at(start) = true;
        #else
        visited[start] = true;
        #endif

        while (!q.empty()) {
            auto [current, distance] = q.front();
            q.pop();

            if (distance == n)
                result.push_back(current);

            const Vector<SharedPtr<Panel>> neighbours = (n > 0) ? adjList.at(current) : reverseAdjList.at(current);

            for (const SharedPtr<Panel>& neighbour: neighbours) {
                #ifndef NDEBUG
                if (!visited.at(neighbour))
                    visited.at(neighbour) = true;
                #else
                if (!visited[neighbour])
                    visited[neighbour] = true;
                #endif

                q.push({neighbour, distance + (n > 0 ? 1 : -1)});
            }
        }
        return result;
    }
};
