#include <bits/stdc++.h>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

const int Inf = INT_MAX;

vector < vector <int> > g, tg, comps;
vector <int> topoSort;
vector <bool> seen;
int V, E;


void readGraph(){

    fin >> V >> E;

    g.resize(V + 1);
    tg.resize(V + 1);
    seen.resize(V + 1);
    comps.reserve(V);
    topoSort.reserve(V);

    for(int e = 0; e < E; ++e){

        int from, to;
        fin >> from >> to;

        g[from].push_back(to);
        tg[to].push_back(from);
    }
}


void topologicalSort(int node){

    seen[node] = true;

    for(const int &adj : g[node])
        if(!seen[adj])
            topologicalSort(adj);

    topoSort.push_back(node);
}


void DFS(int node, vector <int> &SCC){

    seen[node] = false;
    SCC.push_back(node);

    for(const int &adj : tg[node])
        if(seen[adj])
            DFS(adj, SCC);
}


int main(){

    readGraph();

    for(int node = 1; node <= V; ++node)
        if(!seen[node])
            topologicalSort(node);


    for(int idx = V - 1; idx >= 0; --idx)
        if(seen[topoSort[idx]]){

            vector <int> SCC;
            SCC.reserve(V);

            DFS(topoSort[idx], SCC);
            comps.push_back(SCC);
        }



    fout << comps.size() << '\n';
    for(int c = 0; c < (int)comps.size(); ++c){

        for(const int &node : comps[c])
            fout << node << ' ';
        fout << '\n';
    }
}
