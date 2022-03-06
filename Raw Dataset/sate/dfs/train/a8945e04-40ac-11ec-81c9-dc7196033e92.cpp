#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

int n, m, x, y, verificat[30001], a, b, c;
vector<pair<int, int> > graf[30001];

void calc(int sat, int dist) {
    verificat[sat] = 1;

    if (sat == y) {
        out << dist;
        return;
    }

    for (auto edge : graf[sat])
        if (!verificat[edge.first])
            calc(edge.first, edge.second + dist);
}

int main() {
    in >> n >> m >> x >> y;
    while (m--) {
        in >> a >> b >> c;
        graf[a].push_back({b, c});
        graf[b]. push_back({a, -1 * c});
    }

    calc(x, 0);
    return 0;
}
