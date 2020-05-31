#ifndef INC_1_SETGRAPH_H
#define INC_1_SETGRAPH_H

#include <unordered_set>
#include "IGraph.h"


using std::unordered_set;

class SetGraph : public IGraph{
public:
    SetGraph(int count);
    SetGraph(const IGraph& from);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    vector<int> GetNextVertices(int vertex) const override;
    vector<int> GetPrevVertices(int vertex) const override;
private:
    vector<unordered_set<int> > EdgeList;
};


#endif //INC_1_SETGRAPH_H
