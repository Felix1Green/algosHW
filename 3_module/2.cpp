#include <vector>
#include <queue>
#include <cassert>
#include <iostream>

using std::cin;
using std::cout;
using std::vector;
using std::queue;


class ListGraph {
public:
    ListGraph(int count);
    void AddEdge(int from, int to);
    vector<int> getNextVertices(int vertex) const;
    int VerticesCount() const ;
private:
    vector<vector<int> > EdgeList;
};

ListGraph::ListGraph(int count):EdgeList(count){
}

void ListGraph::AddEdge(int from, int to) {

    assert( from >= 0 && to < EdgeList.size() );
    EdgeList[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return EdgeList.size();
}

vector<int> ListGraph::getNextVertices(int vertex) const {
    assert( vertex >= 0 && vertex < EdgeList.size() );
    return EdgeList[vertex];
}

int MinRoutes(const ListGraph& graph,int from, int to){
    vector<bool> visited(graph.VerticesCount(),false);
    vector<int> r(graph.VerticesCount(), -1);
    queue<int> q;
    q.push(from);
    visited[from] = true;r[from] = 0;
    vector<int> ans(graph.VerticesCount(),0);
    while(!q.empty()){
        int edge = q.front();
        q.pop();
        vector<int> Edges = graph.getNextVertices(edge);
        for(int i = 0; i < Edges.size(); i++){
            ans[edge] = (ans[edge]==0?1:ans[edge]);
            if(r[Edges[i]] == r[edge] + 1)
                ans[Edges[i]] += ans[edge];
            if(r[Edges[i]] > r[edge] + 1 || r[Edges[i]] == -1){
                ans[Edges[i]] = ans[edge];
                r[Edges[i]] = r[edge] + 1;
                q.push(Edges[i]);
            }
        }
    }
    return ans[to];
}


int main(){
    int n = 0;
    int m = 0;
    cin >> n >> m;
    ListGraph graph(n);
    int from = 0;int to = 0;
    for(int i = 0 ; i < m ; i ++){
        cin >> from >> to;
        graph.AddEdge(from,to);
        graph.AddEdge(to,from);
    }
    cin >> from >> to;
    int ans = MinRoutes(graph,from,to);
    cout << ans << std::endl;
    return 0;
}