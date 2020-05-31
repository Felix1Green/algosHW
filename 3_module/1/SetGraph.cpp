#include "SetGraph.h"
#include <cassert>

SetGraph::SetGraph(int count):EdgeList(count) {
}

SetGraph::SetGraph(const IGraph &from): EdgeList(from.VerticesCount()) {
    for(int i = 0; i < EdgeList.size(); i ++){
        vector<int> result = from.GetNextVertices(i);
        for(int j : result){
            EdgeList[i].insert(j);
        }
    }
}

void SetGraph::AddEdge(int from, int to){
    assert( from >= 0 && to < EdgeList.size() );
    EdgeList[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return EdgeList.size();
}

vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert( vertex >= 0 && vertex < EdgeList.size() );
    vector<int> result;
    for(int j : EdgeList[vertex]){
        result.push_back(j);
    }
    return result;
}

vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert( vertex >= 0 && vertex < EdgeList.size() );
    vector<int> result;
    for(int i = 0; i < EdgeList.size(); i++){
        for(int j : EdgeList[i]){
            if(j == vertex)
                result.push_back(i);
        }
    }
    return result;
}

