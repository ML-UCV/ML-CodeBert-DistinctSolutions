#include <fstream>
#include <vector>

using namespace std;

ifstream in ("sate.in");
ofstream out ("sate.out");

void dfs ( int nod );

int n, m, x, y;

vector < pair < int, int > > v[30137];

int dp[30137];

int a, b, d;

int main()
{
    in >> n >> m >> x >> y;
    for ( register int i = 1 ; i <= m ; ++i )
    {
        in >> a >> b >> d;
        v[a].push_back ( { b, d } );
        v[b].push_back ( { a, -d } );
    }
    dfs(x);
    out << dp[y];
    return 0;
}

void dfs ( int nod )
{
    for ( auto i : v[nod] )
    {
        int nod2 = i.first;
        int cost = i.second;
        if ( !dp[nod2] )
        {
            dp[nod2] = dp[nod] + cost;
            dfs(nod2);
        }
    }
}
