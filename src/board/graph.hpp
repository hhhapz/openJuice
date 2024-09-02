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

    // Constructor
    Graph(int numVertices);

    // Methods
    void addEdge(int u, int v);
    void setVertexData(int vertex, T data);
    T getVertexData(int vertex) const;
    void printGraph() const;
};

#include "graph.tpp"
