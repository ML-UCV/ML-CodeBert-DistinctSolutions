#include <iostream>
#include <fstream>
#include <vector>
#include <queue>




using namespace std;

vector<vector<pair<int,int> >> graph;
vector<pair<int,int> > apm;
priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > >> heap;
vector<bool> visited;
int n;

void read(){
    ifstream fin("apm.in");

    int m, x, y, c;
    fin>>n>>m;
    graph.resize(n);
    visited.resize(n, false);
    while(m--){
        fin>>x>>y>>c;
        graph[x-1].emplace_back(y-1, c);
        graph[y-1].emplace_back(x-1, c);
    }
}

int main() {
    ofstream fout("apm.out");
    read();
    int total_cost = 0;
    for(auto &e: graph[0])
        heap.push({e.second, {0, e.first}});
    visited[0] = true;
    while(!heap.empty()){
        auto top = heap.top();
        heap.pop();
        int cost = top.first;
        int node = top.second.second;
        if(!visited[node]){
            visited[node] = true;
            apm.push_back(top.second);
            total_cost += cost;
            for(auto &e: graph[node])
                heap.push({e.second, {node, e.first}});
        }
    }
    fout<<total_cost<<' '<<n-1<<'\n';
    for(auto &e: apm)
        fout<<e.first+1<<' '<<e.second+1<<'\n';
    return 0;
}
