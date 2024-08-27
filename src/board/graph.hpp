#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

template <typename T>
struct Graph {
    struct Vertex {
        T data;
        std::vector<int> outEdges;
        std::vector<int> inEdges;
        Vertex(T value);
    };
    std::vector<Vertex> vertices;
    /////////////////////
    // Methods
    /////////////////////

    // Constructor for the graph
    Graph(int vertices);
    // Add a directed edge from u to v
    void addEdge(int u, int v);
    // Set data for a vertex
    void setVertexData(int vertex, T data);
    // Get data for a vertex
    T getVertexData(int vertex) const;
    // Display the graph with outgoing and incoming edges and vertex data
    void printGraph() const;
};

#include "graph.tpp"
