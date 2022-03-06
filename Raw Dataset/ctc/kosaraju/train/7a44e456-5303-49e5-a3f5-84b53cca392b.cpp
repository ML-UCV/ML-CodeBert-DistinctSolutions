#include <bits/stdc++.h>


using namespace std;



const int N_MAX = 100002;



int n, m;



vector <int> outEdges[N_MAX];

vector <int> inEdges[N_MAX];



int order[N_MAX];

int currentIndex;



bool visited[N_MAX];



void dfs (int u)

{

    visited[u] = true;

    for(int v : outEdges[u])

        if(visited[v] == false)

            dfs(v);

    order[++currentIndex] = u;

}



int cntSCC;

vector <int> SCC[N_MAX];



void dfsSCC (int u)

{

    visited[u] = true;

    SCC[cntSCC].push_back(u);

    for(int v : inEdges[u])

        if(visited[v] == false)

            dfsSCC(v);

}





int main()

{

    ifstream fin ("ctc.in");

    ofstream fout ("ctc.out");

    fin >> n >> m;

    for(int i = 1; i <= m; i++)

    {

        int u, v;

        fin >> u >> v;

        outEdges[u].push_back(v);

        inEdges[v].push_back(u);

    }

    for(int i = 1; i <= n; i++)

        if(visited[i] == false)

            dfs(i);

    memset(visited, false, sizeof(visited));

    for(int i = n; i >= 1; i--)

        if(visited[order[i]] == false)

        {

            cntSCC++;

            dfsSCC(order[i]);

        }

    fout << cntSCC << "\n";

    for(int i = 1; i <= cntSCC; i++, fout << "\n")

        for(int u : SCC[i])

            fout << u << " ";

    return 0;

}
