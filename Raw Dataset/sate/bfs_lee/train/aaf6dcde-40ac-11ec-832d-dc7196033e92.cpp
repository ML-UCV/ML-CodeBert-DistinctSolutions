#include <fstream>
#include <queue>

using namespace std;

ifstream cin("sate.in");
ofstream cout("sate.out");

#define DIM 30005

vector <pair<int, int>> v[DIM];
int n, m, x, y, d, st, dr, sel[DIM];

///distanta de la x la y = d iar de la y la x = -d;

static inline void bfs(int k) {
    queue <pair<int, int>> q;
    sel[k] = 1;     ///sa nu trec de 2 ori prin el;
    q.push({k, 0}); ///retin nodul si distana pana la el;
    while(!q.empty()) {
        int nod = q.front().first;
        int dist = q.front().second;
        q.pop();

        if(nod == dr) {
            cout << dist;
            break;
        }

        for(auto e : v[nod])
            if(!sel[e.first]) {
                sel[e.first] = 1;
                q.push({e.first, dist + e.second});
            }
    }
}

int main() {
    cin >> n >> m >> st >> dr;
    for(int i = 1; i <= m; i++) {
        cin >> x >> y >> d;
        v[x].push_back({y, d}); ///retin si distanta dintre puncte;
        v[y].push_back({x, -d});    ///distanta de la y la x = -d !;
    }

    bfs(st);

    return 0;
}
