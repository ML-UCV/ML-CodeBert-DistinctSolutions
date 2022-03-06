#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

const int NodMax = 30005;
const int MuchMax = 100030;

vector < pair < int, int > > G[MuchMax];
queue <int > Q;
bitset < NodMax > viz;
int N,M,X,Y;
int dist[NodMax];

void Read()
{
    scanf("%d %d %d %d", &N, &M, &X, &Y);

    for(int i=1; i<=M; ++i)
    {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        G[x].push_back(make_pair(y,c));
        G[y].push_back(make_pair(x,c));

    }

    if(X > Y)
        swap(X,Y);
}

void Solve()
{
    Q.push(X);

    while(!Q.empty())
    {
        int nodc = Q.front();
        Q.pop();

        viz[nodc] = true;

        if(nodc == Y)
            return;

        for(int i=0; i<G[nodc].size(); ++i)
        {
            if(!viz[G[nodc][i].first])
            {
                if(nodc > G[nodc][i].first)
                    dist[G[nodc][i].first] = dist[nodc] - G[nodc][i].second;

                else
                    dist[G[nodc][i].first] = dist[nodc] + G[nodc][i].second;

                Q.push(G[nodc][i].first);
            }
        }
    }
}

int main()
{
    freopen("sate.in", "r", stdin);
    freopen("sate.out", "w", stdout);

    Read();
    Solve();

    printf("%d", dist[Y]);

    return 0;
}
