#include <bits/stdc++.h>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

const int Inf = INT_MAX;

vector < vector <int> > g, comps;
vector <int> lowlink, pre;
int V, E;

int traversalOrd;

stack <int> Stack;

void readGraph(){

    fin >> V >> E;

    g.resize(V + 1);
    lowlink.resize(V + 1);
    pre.resize(V + 1);
    comps.reserve(V);

    for(int e = 0; e < E; ++e){

        int from, to;
        fin >> from >> to;

        g[from].push_back(to);
    }
}


void cacheSCC(int node){

    vector <int> SCC;
    SCC.reserve(V);

    int stackNode;
    do{

        stackNode = Stack.top();
        Stack.pop();

        lowlink[stackNode] = Inf;
        SCC.push_back(stackNode);
    }while(stackNode != node);

    comps.push_back(SCC);
}


void DFS(int node){

    lowlink[node] = pre[node] = ++traversalOrd;
    Stack.push(node);

    for(const int &adj : g[node])
        if(lowlink[adj] == 0){

            DFS(adj);
            lowlink[node] = min(lowlink[node], lowlink[adj]);
        }
        else lowlink[node] = min(lowlink[node], lowlink[adj]);

    if(lowlink[node] == pre[node])
        cacheSCC(node);
}


int main(){

    readGraph();

    for(int node = 1; node <= V; ++node)
        if(lowlink[node] == 0)
            DFS(node);




    fout << comps.size() << '\n';
    for(int c = 0; c < (int)comps.size(); ++c){

        for(const int &node : comps[c])
            fout << node << ' ';
        fout << '\n';
    }
}
