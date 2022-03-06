#include <fstream>
#include <queue>

using namespace std;

#define N_MAX 30000

struct SATE{
    int nod, cost;
};

vector<SATE> muchii[N_MAX + 1];
int dist[N_MAX + 1];

void dfs( int node ) {
    for ( auto copil: muchii[node] ) {
        if ( dist[copil.nod] == 0 ) {
            if ( copil.nod < node )
                dist[copil.nod] = dist[node] - copil.cost;
            else
                dist[copil.nod] = dist[node] + copil.cost;
            dfs(copil.nod);
        }
    }
}

ifstream cin ( "sate.in" );
ofstream cout ( "sate.out" );

int main() {
    int n, m, x, y, i, a, b, d;
    cin >> n >> m >> x >> y;
    for ( i = 0; i < m; i++ ) {
        cin >> a >> b >> d;
        muchii[a].push_back({b, d});
        muchii[b].push_back({a, d});
    }
    dist[x] = 1;
    dfs(x);
    cout << dist[y] - 1;
    return 0;
}
