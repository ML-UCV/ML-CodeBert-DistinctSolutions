#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <queue>
#include <set>
using namespace std;
int vizitat[200001], n, m, d[200001], tata[200001], cost;
vector<pair<int,int>> adj[200001];
set<int> sol;
priority_queue<int, vector<pair<int, int>>,greater<pair<int, int>>> q;
ifstream f("apm.in");
ofstream g("apm.out");

void initializare()
{
    for(int i = 1; i <= n; i++)
    {
        d[i] = INT_MAX;
        tata[i] = 0;
        vizitat[i] = 1;
    }
}

int main() {
    f >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        f >> x >> y >> z;
        adj[x].emplace_back(y, z);
        adj[y].emplace_back(x, z);
    }
    initializare();
    d[1] = 0;
    for(int i = 1; i <= n; i++)
        q.push(make_pair(d[i], i));
    while(!q.empty() && q.top().first != INT_MAX)
    {
        pair<int,int> m = q.top();
        int u = m.second;
        vizitat[u] = 0;
        q.pop();
        if (u != 1 && sol.find(u) == sol.end())
        {
            cost += d[u];
            sol.insert(u);
        }
        for(auto x : adj[u])
        {
            if(vizitat[x.first] && x.second < d[x.first])
            {
                d[x.first] = x.second;
                tata[x.first] = u;
                q.push(make_pair(d[x.first], x.first));
            }
        }
    }
    g << cost << '\n' << n - 1 << '\n';
    for (auto x : sol)
        g << x << " " << tata[x] << '\n';
    return 0;
}
