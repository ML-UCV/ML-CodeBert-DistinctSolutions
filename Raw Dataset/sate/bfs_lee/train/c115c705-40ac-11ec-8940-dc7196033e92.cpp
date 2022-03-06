#include<cstdio>
#include<vector>

using namespace std;

const int N = 30005;
const int M = 100050;

int n, m, x, y, dist[N], xx[M];
vector< pair<int, int> > vecin[N];

void citire() {
    scanf("%d%d%d%d", &n, &m, &x, &y);

    for (int i = 1; i <= m; ++i) {
        int x1, y1, c;
        scanf("%d%d%d", &x1, &y1, &c);

        vecin[x1].push_back(make_pair(y1, c));
        vecin[y1].push_back(make_pair(x1, -c));
    }
}

inline void schimb(int &x, int &y) {
    int aux = x;
    x = y;
    y = aux;
}

void bfs() {
    xx[0] = x;

    int p = 0, q = 0;

    while (p <= q) {
        for (int i = 0; i < (int) vecin[xx[p]].size(); ++i) {
            int xc = vecin[xx[p]][i].first;

            if (xc != x && (dist[xc] == -1 || dist[xc] > dist[xx[p]] + vecin[xx[p]][i].second) ) {
                dist[xc] = dist[xx[p]] + vecin[xx[p]][i].second;

                xx[++q] = xc;
            }

            if (dist[y] != -1)
                return;
        }

        ++p;
    }
}

int main() {
    freopen("sate.in", "r", stdin);
    freopen("sate.out", "w", stdout);

    citire();

    if (x > y)
        schimb(x, y);

    for (int i = 0; i < N; ++i)
        dist[i] = -1;

    dist[x] = 0;

    bfs();

    printf("%d\n", dist[y]);

    return 0;
}