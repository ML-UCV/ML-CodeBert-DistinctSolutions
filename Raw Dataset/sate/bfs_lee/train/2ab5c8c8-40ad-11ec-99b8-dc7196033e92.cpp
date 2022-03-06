#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

ifstream F("sate.in");
ofstream G("sate.out");

int n, m, x, y, c, X, Y, d[30005];
bitset<30005> v;
vector<pair<int, int> > a[30005];
queue<int> q;

void bfs(int nod)
{
    vector<pair<int, int> > :: iterator it;
    v[nod] = 1;
    q.push(nod);
    while(!q.empty())
    {
        x = q.front();q.pop();
        for(it = a[x].begin(); it != a[x].end(); ++ it)
            if(!v[(*it).f] && !d[(*it).f])
                v[(*it).f] = 1, d[(*it).f] = d[x] + (*it).s, q.push((*it).f);
    }
    G << d[Y];
}

int main()
{
    F >> n >> m >> X >> Y;
    for(int i = 0; i < m; ++ i)
    {
        F >> x >> y >> c;
        a[x].push_back({y, c});
        a[y].push_back({x, -c});
    }
    bfs(X);
    return 0;
}
