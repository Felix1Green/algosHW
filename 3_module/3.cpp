#include <iostream>
#include <vector>
#include <queue>
#include <set>


using std::set;
using std::cin;
using std::cout;
using std::vector;
using std::pair;


class ListGraph{
public:
    ListGraph(int size);
    void AddEdge(int from, int to, int weight);
    int getVertices() const;
    vector<pair<int,int> > getNextVertices(int vertex) const;
private:
    vector<vector<pair<int,int> > > EdgeList;
};

ListGraph::ListGraph(int size):EdgeList(size) {

}

void ListGraph::AddEdge(int from, int to, int weight) {
    EdgeList[from].push_back(pair<int,int>(to,weight));
}

int ListGraph::getVertices() const{
    return EdgeList.size();
}

vector<pair<int,int> > ListGraph::getNextVertices(int vertex) const {
    return EdgeList[vertex];
}


bool Relax(const vector<int>& r,int u,int v,int w){
    return r[v] > r[u] + w;
}


int MinRoute(const ListGraph& graph,int from,int to){
    set<pair<int,int> > q;
    vector<int> r(graph.getVertices(),-1);
    r[from] = 0;
    q.insert(pair<int,int>(from,0));
    while(!q.empty()){
        pair<int,int> u = *q.begin();
        q.erase(q.begin());
        vector<pair<int,int> > Edges = graph.getNextVertices(u.first);
        for(int i = 0; i < Edges.size(); i ++){
            if(r[Edges[i].first] == -1){
                r[Edges[i].first] = r[u.first] + Edges[i].second;
                q.insert(Edges[i]);
            }else if(Relax(r,u.first,Edges[i].first, Edges[i].second)){
                pair<int,int> a = *q.find(pair<int,int>(Edges[i].first,r[Edges[i].first]));
                q.erase(a);
                r[Edges[i].first] = r[u.first] + Edges[i].second;
                q.insert(pair<int,int>(Edges[i].first,r[Edges[i].first]));
            }
        }
    }
    return r[to];
}


int main(){
    int n = 0;int m = 0;
    cin >> n >> m;
    int from = 0;int to = 0;int weight = 0;
    ListGraph a(n);
    for(int i = 0; i < m; i++){
        cin >> from >> to >> weight;
        a.AddEdge(from,to,weight);
        a.AddEdge(to,from,weight);
    }
    cin >> from >> to;
    int ans = MinRoute(a,from,to);
    std::cout << ans << std::endl;
    return 0;
}