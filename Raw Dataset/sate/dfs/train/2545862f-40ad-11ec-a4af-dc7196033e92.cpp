#include <fstream>
#include <vector>

#define MAXN 100002

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

struct two{
    int node, c;
};

vector <two> G[MAXN];

int cost[MAXN], x, y, n, m, aux, l, ok = 0;

inline void DFS(int nod) {
    if (nod == y) {
        fout << cost[nod] - 1;
        ok = 1;
        return;
    }

    if (ok)
        return;

    for (vector <two> :: iterator i = G[nod].begin(); i != G[nod].end(); i++) {
        if (cost[(*i).node] == 0) {
            cost[(*i).node] = cost[nod] + (*i).c;

            DFS((*i).node);
        }
    }
}

inline void Read() {
    int a, b, cc;

    fin >> n >> m >> x >> y;

    for (int i = 1; i <= m; i++) {
        fin >> a >> b >> cc;

        if (a > b) {
            G[a].push_back({b, -cc});
            G[b].push_back({a, cc});
        }
        else
            G[a].push_back({b, cc}),
            G[b].push_back({a, -cc});
    }

    cost[x] = 1;

    DFS(x);
}

int main () {
    Read();

    return 0;
}
