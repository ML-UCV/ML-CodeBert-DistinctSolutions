#include<fstream>
#include<queue>
#include<cmath>
#include<vector>

using namespace std;

ifstream fin( "dmin.in" ); ofstream fout( "dmin.out" );

const int nmax = 1500;
const int mod = 104659;
const double eps = 1e-10;

int ans[ nmax + 1 ];
bool f[ nmax + 1 ];

struct muchie{
    int x; double c;

    muchie() {}
    muchie( int _x, double _c ) : x( _x ), c( _c ) {}
};
typedef vector< muchie > graf;
graf g[ nmax + 1 ];

struct heap{
    int ind, c;
    double sol;

    heap() {}
    heap( int _ind, int _c, double _sol ) {
        ind = _ind, c = _c, sol = _sol;
    }

    inline bool operator < ( const heap &a ) const {
        if ( sol != a.sol ) {
            return ( sol > a.sol );
        }
        return ( ind > a.ind );
    }
};
priority_queue< heap > h;

inline bool egal( double a, double b ) {
    return ( a - eps <= b && b <= a + eps );
}
void extinde( heap x ) {
    for( graf::iterator it = g[ x.ind ].begin(); it != g[ x.ind ].end(); ++ it ) {
        if ( f[ it -> x ] == 0 ) {
            h.push( heap( it -> x, x.c, x.sol + (it -> c) ) );
        }
    }
}
void dijkstra() {
    h.push( heap( 1, 1, 0 ) );
    while ( !h.empty() ) {
        heap x = h.top();
        h.pop();

        if ( f[ x.ind ] == 0 ) {
            f[ x.ind ] = 1;

            while ( !h.empty() && h.top().ind == x.ind && egal( h.top().sol, x.sol ) ) {
                x.c += h.top().c;
                x.c %= mod;
                h.pop();
            }
            ans[ x.ind ] = x.c;

            extinde( x );
        }
    }
}
int main() {
    int n, m;
    fin >> n >> m;
    for( int i = 0; i < m; ++ i ) {
        int x, y; double c;
        fin >> x >> y >> c;
        c = log( c );
        g[ x ].push_back( muchie( y, c ) );
        g[ y ].push_back( muchie( x, c ) );
    }

    dijkstra();
    for( int i = 2; i <= n; ++ i ) {
        fout << ans[ i ] << " ";
    }
    fout << "\n";

    fin.close();
    fout.close();
    return 0;
}
