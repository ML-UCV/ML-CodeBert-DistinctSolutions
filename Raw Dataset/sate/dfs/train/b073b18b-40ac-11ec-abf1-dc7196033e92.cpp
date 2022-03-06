#include <bits/stdc++.h>

#define NMAX 30005
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

vector<pair<int, int> > G[NMAX];
int dp[NMAX], viz[NMAX];
void DFS(int nod, int tata)
{
    for(auto it:G[nod])
        if(it.first != tata && !viz[it.first])
        {
            viz[it.first] = 1;
            dp[it.first] += dp[nod];
            if(it.first < nod)
                dp[it.first] -= it.second;
            else dp[it.first] += it.second;
            DFS(it.first, nod);
        }
}

int main()
{
    int n, m, x, y;
    fin >> n >> m >> x >> y;
    for(int i = 1; i <= m; ++i)
    {
        int x, y, c;
        fin >> x >> y >> c;

        G[x].push_back({y, c});
        G[y].push_back({x, c});
    }

    viz[x] = 1;
    DFS(x, 0);

    fout << dp[y] << '\n';
    return 0;
}
