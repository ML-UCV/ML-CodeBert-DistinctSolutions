#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;
priority_queue< pair< int, int>> q;
const int nMax = 30001;
int d[nMax];
vector< pair< int, int>> v[nMax];

void bfsAdd( int nod, queue< int > &q ) {
    for ( auto &i : v[ nod ] ) {
        if ( d[ i.first ] == 0 ) {
            q.push( i.first );
            if ( i.first > nod )
                d[ i.first ] = d[ nod ] + i.second;
            else
                d[ i.first ] = d[ nod ] - i.second;
        }
    }
}

void bfs( int &x, int &y ) {
    if ( y < x )
        swap( x, y );
    queue< int > q;
    bfsAdd( x, q );

    while ( !q.empty() ) {
        int nod = q.front();
        q.pop();
        bfsAdd( nod, q );
    }
}

int main() {
    int n, m, x, y;
    FILE *fin, *fout;
    fin = fopen( "sate.in", "r" );
    assert( fscanf( fin, "%d%d%d%d", &n, &m, &x, &y ) == 4 );
    for ( int i = 0; i < m; i++ ) {
        int a, b, c;
        assert( fscanf( fin, "%d%d%d", &a, &b, &c ) == 3 );
        v[ a ].push_back( { b, c } );
        v[ b ].push_back( { a, c } );
    }
    fclose( fin );

    bfs( x, y );

    fout = fopen( "sate.out", "w" );
    fprintf( fout, "%d\n", d[ y ] );
    fclose( fout );
    return 0;
}
