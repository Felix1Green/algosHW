#ifndef INC_3_MODULE_LISTGRAPH_H
#define INC_3_MODULE_LISTGRAPH_H
#include "IGraph.h"


class ListGraph : public IGraph{
public:
    ListGraph(int count);
    ListGraph(const IGraph& from);
    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
    vector<vector<int> > EdgeList;
};

#endif //INC_3_MODULE_LISTGRAPH_H
