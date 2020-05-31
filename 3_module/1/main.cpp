#include <iostream>
//#include "SetGraph.h"
//#include "ArcGraph.h"
//#include "ListGraph.h"
#include "MatrixGraph.h"
#include <queue>

using std::queue;
using std::cout;
using std::vector;


void BFS(const IGraph& graph,int vertex, void(*visit)(int)){
    vector<bool> visited(graph.VerticesCount(),false);
    queue<int> q;
    q.push(vertex);
    visited[vertex] = true;
    while(!q.empty()){
        int edge = q.front();
        q.pop();
        visit(edge);
        vector<int> Edges = graph.GetNextVertices(edge);
        for(int i = 0; i < Edges.size(); i++){
            if(!visited[Edges[i]]){
                q.push(Edges[i]);
                visited[Edges[i]] = true;
            }
        }
    }
}


int main(){
//ListGraph listg(10);
    //ArcGraph arcg(10);
//    SetGraph setg(10);
    MatrixGraph matrixg(10);
    for(int i = 0; i < 10; i++){
      //listg.AddEdge(i,(i+1)%10);
        //arcg.AddEdge(i,(i+1)%10);
        //setg.AddEdge(i,(i+1)%10);
        matrixg.AddEdge(i,(i+1)%10);
    }
    //BFS(listg,0,[](int count){std::cout << count << " ";});
    //BFS(arcg,0,[](int count){std::cout << count << " ";});
    //BFS(setg,0,[](int count){std::cout << count << " ";});
    //BFS(matrixg,0,[](int count){std::cout << count << " ";});
}