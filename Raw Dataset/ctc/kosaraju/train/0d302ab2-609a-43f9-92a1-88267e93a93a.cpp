#include <bits/stdc++.h>


using namespace std;



const int NMAX = 100005;

int N, M, topo[NMAX], K;

vector <int> graph[NMAX];

vector <int> revgraph[NMAX];

bitset <NMAX> seen;

vector < vector <int> > ctc;

vector <int> v;



void dfs1(int node)

{

    seen[node] = 1;

    for (auto& x : graph[node])

        if (seen[x] == 0)

            dfs1(x);

    topo[++K] = node;

}



void dfs2(int node)

{

    seen[node] = 1;

    for (auto& x : revgraph[node])

        if (seen[x] == 0)

            dfs2(x);

    v.push_back(node);

}



int main()

{

    ifstream fin("ctc.in");

    ofstream fout("ctc.out");

    fin >> N >> M;

    for (int i = 1;i <= M;++i)

    {

        int u, v;

        fin >> u >> v;

        graph[u].push_back(v);

        revgraph[v].push_back(u);

    }

    for (int i = 1;i <= N;++i)

        if (seen[i] == 0)

            dfs1(i);

    seen.reset();

    for (int i = N;i >= 1;--i)

        if (seen[topo[i]] == 0)

        {

            v.clear();

            dfs2(topo[i]);

            ctc.push_back(v);

        }

    fout << ctc.size() << "\n";

    for (auto& i : ctc)

    {

        for (auto& j : i)

            fout << j << " ";

        fout << "\n";

    }

    fin.close();

    fout.close();

    return 0;

}
