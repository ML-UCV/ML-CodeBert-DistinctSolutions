#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> v[30001];
bool verif[30001];
int dist[30001];
void dfs(int nod)
{
    verif[nod] = 1;
    for ( auto x:v[nod])
    {
        if (!verif[x.first])
        {
            dist[x.first] = dist[nod] + x.second;
            dfs(x.first);
        }
    }
}

int main()
{
    ifstream cin ("sate.in");
    ofstream cout ("sate.out");
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for ( int i = 1; i <= m; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        v[a].push_back({b, d});
        v[b].push_back({a, -d});
    }
    dfs(x);
    cout << dist[y];
    return 0;
}
