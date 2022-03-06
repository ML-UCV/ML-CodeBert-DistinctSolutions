#include <fstream>
#include <vector>

using namespace std;

struct Edge {
    int x, y, cost;
};

int n, m, i, j, k, cmin;
bool viz[200005];
Edge mc, aux, heap[200005];
vector<pair<int, int>> arbore, v[200005];

void pushup(int p) {
    int val;

    val = heap[p].cost;
    while(p > 1 && val < heap[p / 2].cost) {
        swap(heap[p], heap[p / 2]);
        p /= 2;
    }
}

void pushdown(int p) {
    int fiu;

    fiu = 1;
    while(fiu) {
        fiu = 0;
        if(p * 2 <= m) {
            fiu = p * 2;
            if(p * 2 + 1 <= m && heap[p * 2 + 1].cost < heap[p * 2].cost)
                fiu = p * 2 + 1;
            if(heap[p].cost < heap[fiu].cost)
                fiu = 0;
        }
        if(fiu) {
            swap(heap[p], heap[fiu]);
            p = fiu;
        }
    }
}

int main()
{
    ifstream f("apm.in");
    ofstream g("apm.out");

    f >> n >> m;
    while(m) {
        f >> i >> j >> k;
        v[i].emplace_back(j, k);
        v[j].emplace_back(i, k);
        m--;
    }
    f.close();

    for(i = 1; i <= n; i++)
        viz[i] = false;
    viz[1] = true;
    m = 0;
    for(i = 0; i < v[1].size(); i++) {
        mc.x = 1;
        mc.y = v[1][i].first;
        mc.cost = v[1][i].second;
        heap[++m] = mc;
        pushup(m);
    }
    cmin = 0;
    for(k = 1; k < n; k++) {
        mc = heap[1];
        cmin += mc.cost;
        heap[1] = heap[m--];
        pushdown(1);
        arbore.emplace_back(mc.x, mc.y);
        viz[mc.y] = true;
        for(i = 0; i < v[mc.y].size(); i++)
            if(!viz[v[mc.y][i].first]) {
                aux.x = mc.y;
                aux.y = v[mc.y][i].first;
                aux.cost = v[mc.y][i].second;
                heap[++m] = aux;
                pushup(m);
            }
        while(viz[heap[1].x] && viz[heap[1].y]) {
            heap[1] = heap[m--];
            pushdown(1);
        }
    }

    g << cmin << '\n' << n - 1 << '\n';
    for(i = 0; i < arbore.size(); i++)
        g << arbore[i].first << ' ' << arbore[i].second << '\n';
    g.close();

    return 0;
}
