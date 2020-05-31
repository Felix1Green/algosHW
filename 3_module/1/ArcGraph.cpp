#include "ArcGraph.h"

ArcGraph::ArcGraph(int count):size(count) {
}

ArcGraph::ArcGraph(const IGraph &from): size(from.VerticesCount()){
    for(int i = 0; i < from.VerticesCount(); i ++){
        for(int j :from.GetNextVertices(i)){
            EdgeList.emplace_back (i,j);
        }
    }
}

int ArcGraph::VerticesCount() const {
    return size;
}

void ArcGraph::AddEdge(int from, int to) {
    EdgeList.emplace_back(from,to);
}

vector<int> ArcGraph::GetNextVertices(int vertex) const {
    vector<int> result;
    for(auto i : EdgeList){
        if(i.first == vertex )
            result.push_back(i.second);
    }
    return result;
}

vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    vector<int> result;
    for(auto i : EdgeList){
        if(i.second == vertex)
            result.push_back(i.first);
    }
    return result;
}