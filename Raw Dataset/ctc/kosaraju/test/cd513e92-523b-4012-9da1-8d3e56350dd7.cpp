#include <bits/stdc++.h>
using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



const int MAX = 1e5 + 5;



int n, m, ctc;

int viz[MAX];



vector<int> neighbors[MAX], neighborsT[MAX], L, vertices[MAX];



void dfs(int u)

{

    viz[u] = 1;

    for(int v : neighbors[u])

        if(!viz[v])

            dfs(v);

    L.push_back(u);

}



void dfsT(int u)

{

    viz[u] = 1;

    for(int v : neighborsT[u])

        if(!viz[v])

            dfsT(v);

    vertices[ctc].push_back(u);

}



int main()

{

    f >> n >> m;

    for(int i = 1; i <= m; ++i)

    {

        int x, y;

        f >> x >> y;

        neighbors[x].push_back(y);

        neighborsT[y].push_back(x);

    }



    for(int i = 1; i <= n; ++i)

        if(!viz[i])

            dfs(i);



    for(int u : L)

        viz[u] = 0;



    reverse(L.begin(), L.end());



    for(int u : L)

        if(!viz[u])

        {

            ++ctc;

            dfsT(u);

        }



    g << ctc << "\n";

    for(int i = 1; i <= ctc; ++i)

    {

        for(int u : vertices[i])

            g << u << " ";

        g << "\n";

    }

    return 0;

}
