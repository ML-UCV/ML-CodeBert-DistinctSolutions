#include <fstream>
#include <algorithm>
#include <vector>


using namespace std;

struct Edge {
    int x, y, cost;
};

int n, m, i, j, rad1, rad2, cmin;
int h[200005], rad[200005];
Edge muchie;
vector<Edge> mc;
vector<pair<int, int>> apcm;

bool cmp(Edge e1, Edge e2) {
    return e1.cost < e2.cost;
}

int root(int x) {
    while(rad[x] != 0)
        x = rad[x];
    return x;
}

int main() {
    ifstream f("apm.in");
    ofstream g("apm.out");

    f >> n >> m;
    for(i = 0; i < m; i++) {
        f >> muchie.x >> muchie.y >> muchie.cost;
        mc.push_back(muchie);
    }
    f.close();

    sort(mc.begin(), mc.end(), cmp);
    for(i = 1; i <= n; i++) {
        rad[i] = 0;
        h[i] = 0;
    }

    j = 0;
    cmin = 0;
    for(i = 0; i < m; i++) {
        rad1 = root(mc[i].x);
        rad2 = root(mc[i].y);
        if(rad1 != rad2) {
            apcm.emplace_back(mc[i].x, mc[i].y);
            cmin += mc[i].cost;
            if(h[rad1] > h[rad2])
                rad[rad2] = rad1;
            else {
                rad[rad1] = rad2;
                if(h[rad1] == h[rad2])
                    h[rad2]++;
            }
            j++;
            if(j == n - 1)
                break;
        }
    }

    g << cmin << '\n' << n - 1 << '\n';
    for(i = 0; i < apcm.size(); i++)
        g << apcm[i].first << ' ' << apcm[i].second << '\n';
    g.close();

    return 0;
}
