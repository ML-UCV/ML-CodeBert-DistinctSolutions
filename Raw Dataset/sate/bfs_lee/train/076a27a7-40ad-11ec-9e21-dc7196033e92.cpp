#include <bits/stdc++.h>
#define nr first
#define cost second
using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

int n, m, x, y;

int a, b, c;
vector< pair<int, int> > l[30005];
///        (vecin, cost)
bool vizitat[30005];
long long d[30005];

void bfs( int start )
{
    queue<int> coada;
    int nod;
    pair<int, int> vecin;

    coada.push(start);
    vizitat[start] = true;

    while( !coada.empty() )
    {
        nod = coada.front();
        coada.pop();

        for( unsigned int i = 0; i < l[nod].size(); i++ )
        {
            vecin = l[nod][i];

            if( vizitat[ vecin.nr ] == false )
            {
                coada.push( vecin.nr );
                vizitat[ vecin.nr ] = true;
                d[ vecin.nr ] = d[nod] + vecin.cost * (  (vecin.nr > nod)? 1 : -1 );
            }
        }
    }
}

int main()
{
    in>>n>>m>>x>>y;
    for( int i = 1; i <= m; i++ )
    {
        in>>a>>b>>c;
        l[a].push_back( make_pair(b, c) );
        l[b].push_back( make_pair(a, c) );
    }

    bfs(x);

    out<<d[y];

    return 0;
}
