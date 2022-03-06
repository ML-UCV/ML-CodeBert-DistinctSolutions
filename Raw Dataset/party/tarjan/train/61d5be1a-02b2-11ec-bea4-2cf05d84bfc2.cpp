#include<fstream>
#include<vector>
#include<cstring>

using namespace std;

ifstream fin( "party.in" ); ofstream fout( "party.out" );

typedef vector< int > graf;

const int nmax = 100;
int n, nr_comp;
int c[ 2 * nmax + 1 ];
bool viz[ 2 * nmax + 1 ];
graf g[ 2 * nmax + 1 ][ 2 ];

vector< int > ord, ans;

inline int neg( int x ) {
    if( x <= n ) {
        return x + n;
    }
    return x - n;
}
void muchie( int x, int y ) {
    g[ neg( x ) ][ 0 ].push_back( y );
    g[ neg( y ) ][ 0 ].push_back( x );

    g[ y ][ 1 ].push_back( neg( x ) );
    g[ x ][ 1 ].push_back( neg( y ) );
}
void dfs( int nod, int ind ) {
    viz[ nod ] = 1;

    for( graf::iterator it = g[ nod ][ ind ].begin(); it != g[ nod ][ ind ].end(); ++ it ) {
        if ( viz[ *it ] == 0 ) {
            dfs( *it, ind );
        }
    }

    if ( ind == 0 ) {
        ord.push_back( nod );
    } else {
        c[ nod ] = nr_comp;
    }
}
void plus_minus() {
    for( int i = 1; i <= 2 * n; ++ i ) {
        if ( viz[ i ] == 0 ) {
            dfs( i, 0 );
        }
    }
    memset( viz, 0, sizeof( viz ) );
    nr_comp = 0;
    for( int i = ord.size() - 1; i >= 0; -- i ) {
        if ( viz[ ord[ i ] ] == 0 ) {
            ++ nr_comp;
            dfs( ord[ i ], 1 );
        }
    }
}
int main() {
    int m;
    fin >> n >> m;
    for( int i = 0; i < m; ++ i ) {
        int x, y, z;
        fin >> x >> y >> z;
        if ( z == 0 ) {
            muchie( x, y );
        } else if ( z == 1 ) {
            muchie( x, neg( y ) );
        } else if ( z == 2 ) {
            muchie( y, neg( x ) );
        } else {
            muchie( neg( x ), neg( y ) );
        }
    }

    plus_minus();

    for( int i = 1; i <= n; ++ i ) {
        if ( c[ i ] > c[ i + n ] ) {
            ans.push_back( i );
        }
    }
    fout << ( int )ans.size() << "\n";
    for( int i = 0; i < ( int )ans.size(); ++ i ) {
        fout << ans[ i ] << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
