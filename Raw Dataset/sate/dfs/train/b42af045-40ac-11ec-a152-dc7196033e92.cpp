#include <fstream>
#include <vector>

using namespace std;

ifstream fin ("sate.in");
ofstream fout ("sate.out");

typedef struct {
    int to;
    int km;
} edge;

vector < edge > graf[30001];

int n, m, x, y, dis[30001], viz[30001];

void DFS ( int node ) {
    viz[ node ] = 1;

    for ( unsigned int l = 0; l < graf[node].size(); l++ ) {

        int to = graf[node][l].to, km = graf[node][l].km;
        if ( ! viz[to] ) {

            if ( !dis[to] ) {

                if ( to > node )
                    dis[to] = dis[node] + km;
                else
                    dis[to] = dis[node] - km;
            }
            DFS ( to );
        }
    }
}

void read () {
    fin >> n >> m >> x >> y;

    int from;
    for (int i = 1; i <= m; i++) {
        edge e1, e2;
        fin >> from >> e1.to >> e1.km;
        e2.to = from, e2.km = e1.km;
        graf[ from ].push_back( e1 );
        graf[ e1.to ].push_back ( e2 );

        if ( from == x )
            dis[ e1.to ] = e1.km;
    }
}

int main()
{
    read ();

    dis[x] = 0;
    DFS ( x );

    fout << dis[y] << "\n";
    return 0;
}
