#include "board.hpp"

Board::Board(int id, int numVertices, 
      const std::vector<std::vector<int>>& outEdges, 
      const std::vector<std::vector<int>>& inEdges, 
      const std::vector<Panels>& panelData): 
      Graph<Panels>(numVertices), id(id)
      {
    for (int i = 0; i < numVertices; ++i)
        setVertexData(i, panelData[i]);
    // Set out-edges for each panel
    for (int u = 0; u < outEdges.size(); ++u) {
        for (int v: outEdges[u]) {
            if (u >= 0 && u < vertices.size() && v >= 0 && v < vertices.size())
                vertices[u].outEdges.push_back(v);
        }
    }
    // Set in-edges for each panel
    for (int v = 0; v < inEdges.size(); ++v) {
        for (int u: inEdges[v]) {
            if (u >= 0 && vertices.size() && v >= 0 && v < vertices.size())
                vertices[v].inEdges.push_back(u);
        }
    }
}