
#ifndef INC_1_ARCGRAPH_H
#define INC_1_ARCGRAPH_H
#include "IGraph.h"

class ArcGraph : public IGraph{
public:
    ArcGraph(int count);
    ArcGraph(const IGraph& from);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    vector<int> GetNextVertices(int vertex) const override;
    vector<int> GetPrevVertices(int vertex) const override;
private:
    int size;
    vector<std::pair<int,int>> EdgeList;
};


#endif //INC_1_ARCGRAPH_H
