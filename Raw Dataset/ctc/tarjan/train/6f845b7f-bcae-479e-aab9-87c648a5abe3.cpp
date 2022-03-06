#include <bits/stdc++.h>

using namespace std;
ifstream fin("ctc.in");
ofstream fout("ctc.out");

int n, m, sccCount = 0, cnt = 0;
stack<int> stiva;
bool onSt[1000001];
int vis[1000001], low[1000001];
vector<int> adj[1000001], con;
vector<vector<int>> result;

void dfs(int node)
{
    stiva.push(node);
    onSt[node] = true;
    ++cnt;
    vis[node] = cnt;
    low[node] = cnt;

    for (int nbh : adj[node])
    {
        if (vis[nbh] == 0)
            dfs(nbh);
        if (onSt[nbh])
            low[node] = min(low[nbh], low[node]);
    }
    if (vis[node] == low[node])
    {
        ++sccCount;
        con.clear();
        while (stiva.top() != node)
        {
            onSt[stiva.top()] = false;
            low[stiva.top()] = vis[node];
            con.push_back(stiva.top());
            stiva.pop();
        }
        onSt[node] = false;
        low[node] = vis[node];
        con.push_back(node);
        stiva.pop();
        result.push_back(con);
    }
}

int main()
{
    fin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        fin >> x >> y;
        adj[x].push_back(y);
    }

    for (int i = 1; i <= n; ++i)
        if (vis[i] == 0)
            dfs(i);
    fout << sccCount << "\n";
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
            fout << result[i][j] << " ";
        fout << "\n";
    }
    return 0;
}
