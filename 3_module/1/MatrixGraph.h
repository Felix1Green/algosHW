#ifndef INC_3_MODULE_MATRIXGRAPH_H
#define INC_3_MODULE_MATRIXGRAPH_H
#include "IGraph.h"

class MatrixGraph : public IGraph{
public:
    MatrixGraph(int count);
    MatrixGraph(const IGraph& from);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    vector<int> GetNextVertices(int vertex) const override;
    vector<int> GetPrevVertices(int vertex) const override;
private:
    vector< vector<int> > EdgeList;
};

#endif //INC_3_MODULE_MATRIXGRAPH_H
