#include <iostream>
#include <fstream>
#include <algorithm>
#include<vector>

using namespace std;
int tata[200001], h[200001], n, m;
vector<pair<pair<int,int>, int>> graf, apcm;
ifstream f("apm.in");
ofstream g("apm.out");

bool cmp (pair<pair<int,int>, int> a, pair<pair<int,int>, int> b)
{
    if (a.second < b.second)
        return 1;
    else
        return 0;

}

void initializare (int u)
{
    tata[u] = 0; h[u] = 0;
}

int reprezentare (int u)
{
    while(tata[u] != 0)
        u = tata[u];
    return u;
}

void reuneste(int u, int v)
{
    int ru = reprezentare(u);
    int rv = reprezentare(v);
    if (h[ru] > h[rv])
        tata[rv] = ru;
    else
    {
        tata[ru] = rv;
        if(h[ru] == h[rv])
            h[rv]++;
    }
}

int kruskal()
{
    sort(graf.begin(), graf.end(), cmp);
    for (int v = 1; v <= n; v++)
        initializare(v);
    int nr = 0;
    int cost = 0;
    for (auto x : graf)
        if(reprezentare(x.first.first) != reprezentare(x.first.second))
        {
            apcm.push_back(x);
            cost += x.second;
            reuneste(x.first.first, x.first.second);
            nr++;
            if(nr == n - 1)
                break;
        }
    return cost;
}

int main()
{
    f >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y, cost;
        f >> x >> y >> cost;
        graf.push_back(make_pair(make_pair(x, y), cost));
    }
    int cost_final = kruskal();
    g << cost_final << '\n' << n - 1 << '\n';
    for(auto x : apcm)
    {
        g << x.first.first << " " << x.first.second << '\n';
    }
    return 0;
}
