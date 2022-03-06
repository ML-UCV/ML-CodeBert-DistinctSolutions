#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef pair<int, int> edge;

int  n, m, s, d;
bool viz[30001], done;
vector<edge> g[30001];

void citire();
void afisare(int);
void dfs(int, int);


int main() {
    citire();

    dfs(s, 0);

    return 0;
}


void dfs(int x, int cost) {
    viz[x] = true;
    if (x == d) {
        afisare(cost);
        done = true;
        return;
    }

    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i].second;
        if (viz[y]) continue;
        dfs(y, cost + g[x][i].first);
        if (done) return;
    }
}

void afisare(int cost) {
    ofstream out("sate.out");
    out << cost;
    out.close();
}

void citire() {
    ifstream in("sate.in");
    in >> n >> m >> s >> d;

    for (int i = 1, x, y, c; i <= m; ++i) {
        in >> x >> y >> c;
        g[x].push_back(make_pair(c, y));
        g[y].push_back(make_pair(-c, x));
    }

    in.close();
}
