#include <iostream>
#include <fstream>
#include <vector>

std:: ifstream in("ctc.in");
std:: ofstream out("ctc.out");

int n, m, g_count;
bool marked[100001],marked_scc[100001];
std:: vector<int> g[100001],g_rev[100001],ordered,scc[1000001];

void dfs(int node){
    if(!marked[node]) {
        marked[node] = true;
        for(int i = 0; i < g[node].size(); i++)
            dfs(g[node][i]);
        ordered.push_back(node);
    }
}

void dfs_rev(int node, int counter) {
    if(!marked_scc[node])
    {
        marked_scc[node] = counter;
        scc[counter].push_back(node);
        for(int i = 0; i < g_rev[node].size(); i++)
            dfs_rev(g_rev[node][i], counter);
    }
}

int main(){
    in >> n >> m;
    for( int i = 0; i < m; i++){
        int a,b;
        in >> a >> b;
        g[a].push_back(b);
        g_rev[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
        if(!marked[i])
            dfs(i);
    for(int i = n - 1; i >= 0; i--)
        if(!marked_scc[ordered[i]])
            dfs_rev(ordered[i], ++g_count);
    out << g_count << '\n';
    for(int i = 1; i <= g_count; i++) {
        for (int j = 0; j < scc[i].size(); j++)
            out << scc[i][j] << " ";
        out << '\n';
    }

    return 0;
}
