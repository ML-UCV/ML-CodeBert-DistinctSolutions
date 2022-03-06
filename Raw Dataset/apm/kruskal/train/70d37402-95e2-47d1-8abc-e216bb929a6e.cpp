#include <fstream>
#include <algorithm>
using namespace std;

class muc {
public:
    int x, y, c;
    bool taken;
    friend istream & operator>>(istream &in, muc &tmp) {
        in >> tmp.x >> tmp.y >> tmp.c;
        return in;
    }
};

int n, m;
int cmin, nedges;
int Parent[200005], rang[200005];
muc edge[400005];


inline void read();
inline void print();
inline void solve();

inline void init();
inline void Kruskal();

inline int Find(int);
inline void Union(int, int);

bool cmp(muc &, muc &);

int main(int argc, const char * argv[]) {

    read();
    solve();
    print();
    return 0;
}

inline void read() {
    ifstream f("apm.in");
    f >> n >> m;
    for (int i = 1; i <= m; ++i)
        f >> edge[i];
    f.close();
}

inline void solve() {
    init();
    Kruskal();
}

inline void print() {
    ofstream g("apm.out");
    g << cmin << '\n' << nedges << '\n';
    for (int i = 1; i <= m; ++i) {
        if (edge[i].taken == 1)
            g << edge[i].x << ' ' << edge[i].y << '\n';
    }
    g.close();
}

inline void init() {
    for (int i = 1; i <= n; ++i)
        Parent[i] = i;
    sort(edge + 1, edge + m + 1, cmp);
}

inline void Kruskal() {
    for (int i = 1; i <= m; ++i)
        if (Find(edge[i].x) != Find(edge[i].y)) {
            Union(edge[i].x, edge[i].y);
            cmin += edge[i].c;
            edge[i].taken = 1;
            ++nedges;
        }
}

inline int Find(int node) {
    if (Parent[node] != node)
        Parent[node] = Find(Parent[node]);
    return Parent[node];
}

inline void Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);

    if (px == py)
        return;
    if (rang[px] < rang[py])
        Parent[px] = py;
    else if (rang[px] > rang[py])
        Parent[py] = px;
    else {
        Parent[px] = py;
        ++rang[py];
    }

}

bool cmp(muc & a, muc & b) {
    return a.c < b.c;
}
