#include <iostream>
#include "ListGraph.h"
#include <cassert>

ListGraph::ListGraph(int count):EdgeList(count){
}

ListGraph::ListGraph(const IGraph &from): EdgeList(from.VerticesCount()) {
    for(int i = 0; i < EdgeList.size();i++){
        EdgeList[i] = from.GetNextVertices(i);
    }
}

void ListGraph::AddEdge(int from, int to) {

    assert( from >= 0 && to < EdgeList.size() );
    EdgeList[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return EdgeList.size();
}

vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert( vertex >= 0 && vertex < EdgeList.size() );
    return EdgeList[vertex];
}

vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert( vertex >= 0 && vertex < EdgeList.size() );
    vector<int> result;
    for(int i = 0; i < EdgeList.size();i++){
        for(int j = 0; j < EdgeList[i].size(); j++){
            if(EdgeList[i][j] == vertex)
                result.push_back(i);
        }
    }
    return result;
}