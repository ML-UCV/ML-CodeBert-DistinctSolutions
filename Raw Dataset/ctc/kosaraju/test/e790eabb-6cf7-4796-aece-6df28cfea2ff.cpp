#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

int n, m, x, y, no_SCC;
vector<vector<int>> arches, op_arches, SCCs;
vector<bool> visited;
stack<int> order;

void dfs(int node){
    visited[node] = true;
    for(auto &arch: arches[node])
        if(!visited[arch])
            dfs(arch);
    order.push(node);
}

void dfs_oposite(vector<int> &SCC, int node){
    visited[node] = false;
    SCC.emplace_back(node);
    for(auto &arch: op_arches[node])
        if(visited[arch])
            dfs_oposite(SCC, arch);
}

void read(){
    fin>>n>>m;
    arches.resize(n);
    op_arches.resize(n);
    while(m--){
        fin>>x>>y;
        x--;y--;
        arches[x].emplace_back(y);
        op_arches[y].emplace_back(x);
    }
}

void kosarju(){
    visited.resize(n, false);
    for(int i=0;i<n;++i)
        if(!visited[i])
            dfs(i);
    while(!order.empty()){
        int v = order.top();
        order.pop();
        if(visited[v]){
            SCCs.emplace_back();
            dfs_oposite(SCCs[no_SCC++], v);
        }
    }
}

void write(){
    fout<<no_SCC;
    for(int i=0;i<no_SCC;++i){
        fout<<'\n';
        for(auto &c: SCCs[i])
            fout<<c+1<<' ';
    }
}

int main() {
    read();
    kosarju();
    write();
    return 0;
}
