#include "graph.hpp"

template <typename T>
Graph<T>::Vertex::Vertex(T value):
    data(value) {}

template <typename T>
Graph<T>::Graph(int numVertices) {
    vertices.reserve(numVertices);
    for (int i = 0; i < numVetices; ++i) vertices.push_back(T());
}

template <typename T>
void Graph<T>::addEdge(int u, int v) {
    if (u >= 0 && u < vertices.size() && v >= 0 && v < vertices.size()) {
        vertices[u].outEdges.push_back(v);
        vertices[v].inEdges.push_back(u);
    } else
        std::cerr << "Error: Vertex index out of bounds.\n";
}

template <typename T>
void Graph<T>::setVertexData(int vertex, T data) {
    if (vertex >= 0 && vertex < vertices.size())
        vertices[vertex].data = data;
    else
        std::cerr << "Error: Vertex index out of bounds." << std::endl;
}