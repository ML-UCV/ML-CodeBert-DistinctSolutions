#include <bits/stdc++.h>

using namespace std;

ifstream f("ctc.in");
ofstream g("ctc.out");

const int nmax = 1e5 + 6;

vector <int> G[nmax];
vector <int> TG[nmax];
stack <int> topologicSort;

bool vizited[nmax];

void normalDfs(int node)
{
    vizited[node] = true;
    for (auto next : G[node])
        if (!vizited[next])
            normalDfs(next);
    topologicSort.push(node);
}

vector <int> components[nmax];

void trsDfs(int node, const int comp)
{
    vizited[node] = false;
    components[comp].push_back(node);
    for (auto next : TG[node])
        if (vizited[next])
            trsDfs(next, comp);
}

int main()
{
    int n, m;
    f >> n >> m;
    for (int i = 1; i <= m; ++ i)
    {
        int u, v;
        f >> u >> v;
        G[u].push_back(v);
        TG[v].push_back(u);
    }
    for (int node = 1; node <= n; ++ node)
        if (!vizited[node])
            normalDfs(node);

    int cnt = 0;
    while (!topologicSort.empty())
    {
        int startNode = topologicSort.top();
        topologicSort.pop();
        if (vizited[startNode])
            trsDfs(startNode, ++ cnt);
    }
     g << cnt << '\n';
    for (int i = 1; i <= cnt; ++ i)
    {
        for (auto el : components[i])
            g << el << " ";
        g << '\n';
    }


}
