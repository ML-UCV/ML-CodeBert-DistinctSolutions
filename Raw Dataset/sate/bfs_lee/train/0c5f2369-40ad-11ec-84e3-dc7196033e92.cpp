#include <cstdio>
#include <queue>
#define NMAX 30000
#define MMAX 100024

using namespace std;

int n, m, nr, lst[1 + MMAX], urm[1 + 2 * MMAX], viz[1 + 2 * NMAX], s, f, dist[1 + 2 * NMAX];

struct M {
    int p, d;
};

M vf[1 + 2 * MMAX];

queue <int> a;
void adauga ( int x, int y, int d ) {
    ++nr;
    vf[nr].p = y;
    vf[nr].d = d;
    urm[nr] = lst[x];
    lst[x] = nr;
}

void bfs ( ) {
    while ( !a.empty() ) {
        M x;
        x.p = a.front();
        a.pop();
        int p = lst[x.p];
        M y;
        while ( p ) {
            y = vf[p];
            if ( !viz[y.p] ) {
                a.push ( y.p );
                if (y.p < x.p)
                    dist[y.p] = dist[x.p] - y.d;
                else
                    dist[y.p] = dist[x.p] + y.d;
                viz[y.p] = 1;
            }

            p = urm[p];
        }
    }
}

int main() {
    FILE *fin = fopen ( "sate.in", "r" );
    fscanf ( fin, "%d%d%d%d", &n, &m, &s, &f );
    int i, x, y, d;
    for ( i = 1; i <= m; ++i ) {
        fscanf ( fin, "%d%d%d", &x, &y, &d );
        adauga ( y, x, d );
        adauga ( x, y, d );
    }
    fclose ( fin );
    a.push(s);

    bfs();

    FILE *fout = fopen ( "sate.out", "w" );
    fprintf ( fout, "%d", dist[f]);
    fclose ( fout );

    return 0;
}
