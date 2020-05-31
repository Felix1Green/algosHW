#include "MatrixGraph.h"
#include <cassert>

MatrixGraph::MatrixGraph(int count): EdgeList(count) {
    for(int i = 0; i < EdgeList.size(); i++){
        EdgeList[i].resize(count,0);
    }
}

MatrixGraph::MatrixGraph(const IGraph &from):EdgeList(from.VerticesCount()) {
    for(int i = 0; i < EdgeList.size(); i++){
        vector<int> result = from.GetNextVertices(i);
        for(int j : result){
            EdgeList[i][j] = 1;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    assert( from >= 0 && to < EdgeList.size() );
    EdgeList[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
   return EdgeList.size();
}

vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert( vertex >= 0 && vertex < EdgeList.size() );
    return EdgeList[vertex];
}

vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert( vertex >= 0 && vertex < EdgeList.size() );
    vector<int> result;
    for(int i = 0; i < EdgeList.size(); i++){
        result.push_back(EdgeList[i][vertex]);
    }
    return result;
};