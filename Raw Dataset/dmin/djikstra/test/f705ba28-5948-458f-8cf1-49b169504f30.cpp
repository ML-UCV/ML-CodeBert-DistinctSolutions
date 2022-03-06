#include <bits/stdc++.h>
using namespace std;

fstream in ( "dmin.in" , ios::in );
fstream out( "dmin.out", ios::out );

const int DIM = 1505;
const int MOD = 104659;
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-10;

int cnt[DIM];
long double dst[DIM];

vector<pair<long double, int>> edg[DIM];
priority_queue< pair<long double, int>,
               vector <pair<long double, int>>,
               greater<pair<long double, int>>> prq;

inline int sgn( long double x ) {
    if( fabs( x ) < EPS )
        return 0;
    return ( x < 0 ) ? -1 : 1;
}

int main( void ) {
    ios::sync_with_stdio( false );

    int n, m;
    in >> n >> m;

    for( int i = 1; i <= m; i ++ ) {
        int x, y, z;
        in >> x >> y >> z;

        edg[x].push_back( make_pair( log10( z ), y ) );
        edg[y].push_back( make_pair( log10( z ), x ) );
    }

    fill( dst + 2, dst + n + 1, INF ); cnt[1] = 1;
    for( prq.push( make_pair( 0, 1 ) ); !prq.empty(); prq.pop() ) {
        pair<long double, int> x = prq.top();

        if( sgn( x.first - dst[x.second] ) > 0 )
            continue;

        for( pair<long double, int> y : edg[x.second] ) {
            if( sgn( dst[y.second] - ( dst[x.second] + y.first ) ) > 0 ) {
                dst[y.second] = dst[x.second] + y.first;
                cnt[y.second] = cnt[x.second];

                prq.push( make_pair( dst[y.second], y.second ) );
            }
            else {
                if( sgn( dst[y.second] - ( dst[x.second] + y.first ) ) == 0 )
                    cnt[y.second] = ( cnt[y.second] + cnt[x.second] ) % MOD;
            }
        }
    }

    for( int i = 2; i <= n; i ++ )
        out << cnt[i] << " ";
    out << endl;

    return 0;
}
