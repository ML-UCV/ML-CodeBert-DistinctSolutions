#include <bits/stdc++.h>
using namespace std;

int n, m, t;
vector<int> adj[100001];
int ind[100001];
int low[100001];
int vizitat[100001];
stack<int> s;
vector<set<int>> ans;

void components(int current)
{
    ind[current] = ++t;
    low[current] = t;
    vizitat[current] = 1;
    s.push(current);
    for(auto x : adj[current])
    {
        if(ind[x] == -1)
            {
            components(x);
            low[current] = min(low[current], low[x]);
            }
        else if(vizitat[x] == 1)
            low[current] = min(low[current], ind[x]);
    }
    int w = 0;
    set<int> temp;
    if(low[current] == ind[current])
    {
        while(s.top() != current)
        {
            w = s.top();
            temp.insert(w);
            vizitat[w] = 0;
            s.pop();
        }
        w = s.top();
        temp.insert(w);
        vizitat[w] = 0;
        s.pop();
        ans.push_back(temp);
    }
}

void Tarjan()
{
    for(int i = 1; i <= n; i++)
    {
        ind[i] = -1;
        low[i] = -1;
        vizitat[i] = 0;
    }
    for(int i = 1; i <= n; i++)
        if(ind[i] == -1)
            components(i);
}
int main() {
    ifstream f("ctc.in");
    ofstream g("ctc.out");
    f >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x,y;
        f >> x >> y;
        adj[x].push_back(y);
    }
    Tarjan();
    g << ans.size() << '\n';
    for(auto &x : ans)
    {
        for(auto el : x)
            g << el << " ";
        g << '\n';
    }
    f.close();
    g.close();
    return 0;
}
