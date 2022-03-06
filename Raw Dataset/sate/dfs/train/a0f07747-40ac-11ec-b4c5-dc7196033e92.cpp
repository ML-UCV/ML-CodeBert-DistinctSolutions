#include <stdio.h>
#include <vector>

#define MAX_N 100000

using namespace std;

struct muchie {
    int to, d;
};

int viz[MAX_N], dist[MAX_N];
vector <muchie> muchii[MAX_N];

void dfs( int nod ) {
    int nextNod, d, i;

    viz[nod] = 1;
    for ( i = 0; i < muchii[nod].size(); i++ ) {
        nextNod = muchii[nod][i].to;
        d = muchii[nod][i].d;
        if ( !viz[nextNod] ) {
            if ( nod < nextNod )
                dist[nextNod] = dist[nod] + d;
            else
                dist[nextNod] = dist[nod] - d;
            dfs( nextNod );
        }
    }
}

int main() {
    FILE *fin, *fout;
    int n, m, x, y, a, b, d, i;

    fin = fopen( "sate.in", "r" );
    fscanf( fin, "%d%d%d%d", &n, &m, &x, &y );
    x--;
    y--;
    for ( i = 0; i < m; i++ ) {
        fscanf( fin, "%d%d%d", &a, &b, &d );
        a--;
        b--;
        muchii[a].push_back( { b, d } );
        muchii[b].push_back( { a, d } );
    }
    fclose( fin );

    dfs( x );

    fout = fopen( "sate.out", "w" );
    fprintf( fout, "%d", dist[y] );
    fclose( fout );

    return 0;
}
