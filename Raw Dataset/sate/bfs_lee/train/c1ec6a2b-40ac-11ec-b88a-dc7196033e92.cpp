#include <fstream>
#include <vector>

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int n, m, x, y, i, j, d;
bool viz[30005];
vector<pair<int, int>> dist[30005];

void bfs(const int &k, const int &dst) {
    int ii;

    if(k == y && !viz[k]) {
        g << dst << '\n';
        viz[k] = true;
        return;
    }
    else {
        viz[k] = true;
        for(ii = 0; ii < dist[k].size(); ii++)
            if(!viz[dist[k][ii].first])
                bfs(dist[k][ii].first, dst + dist[k][ii].second);
    }
}

int main() {
    f >> n >> m >> x >> y;
    while(m) {
        f >> i >> j >> d;

        dist[i].emplace_back(j, d);
        dist[j].emplace_back(i, -d);
        m--;
    }
    f.close();

    bfs(x, 0);
    g.close();

    return 0;
}
