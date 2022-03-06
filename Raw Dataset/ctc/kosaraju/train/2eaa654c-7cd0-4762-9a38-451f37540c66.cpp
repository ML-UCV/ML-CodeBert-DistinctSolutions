#include <cstdio>
#include <cassert>
#include <cctype>
#include <vector>
#include <stack>
#include <bitset>
#include <fstream>
using namespace std;
const int nMax = 100001;
vector< int > v1[nMax];
vector< int > v2[nMax];
stack< int > stiva;
bitset< nMax > vizitat;
int ctc[nMax];
int co( 0 );

void dfs( int nod ) {
    vizitat[ nod ] = true;
    for ( vector< int >::iterator it = v1[ nod ].begin(); it != v1[ nod ].end(); it++ ) {
        if ( vizitat[ *it ] == false )
            dfs( *it );
    }
    stiva.push( nod );
}

void ctc_dfs( int nod ) {
    ctc[ nod ] = co;
    for ( vector< int >::iterator it = v2[ nod ].begin(); it != v2[ nod ].end(); it++ ) {
        if ( ctc[ *it ] == 0 )
            ctc_dfs( *it );
    }
}

int main() {
    int n, m;
    ifstream fin("ctc.in");
    FILE *fout;
    fin >> n >> m;
    for ( int i = 0; i < m; i++ ) {
        int a, b;
        fin >> a >> b;
        a--;
        b--;
        v1[ a ].push_back( b );
        v2[ b ].push_back( a );
    }
    for ( int i = 0; i < n; i++ )
        if ( vizitat[ i ] == false )
            dfs( i );
    while ( !stiva.empty() ) {
        int nod = stiva.top();
        stiva.pop();
        if ( ctc[ nod ] == 0 ) {
            co += 1;
            ctc_dfs( nod );
        }
    }
    fout = fopen( "ctc.out", "w" );
    fprintf( fout, "%d\n", co );
    vector< int > afisare[n + 1];
    for ( int i = 0; i < n; i++ )
        afisare[ ctc[ i ] ].push_back( i + 1 );
    for ( int i = 1; i <= n; i++ ) {
        for ( unsigned j = 0; j < afisare[ i ].size(); j++ ) {
            fprintf( fout, "%d ", afisare[ i ][ j ] );
        }
        fputc( '\n', fout );
    }
    fclose( fout );
    return 0;
}
