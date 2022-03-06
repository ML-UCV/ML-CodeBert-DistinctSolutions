#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

const int marime = 200005;

int suma;
bool f[marime];
vector<pair<int, int>> sir;
vector<pair<int, int>> mat[marime];
priority_queue<pair<int, pair<int, int>>> q;

int main() {
    int n, m;
    fin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int x, y, cost;
        fin >> x >> y >> cost;

        mat[x].push_back({y, cost});
        mat[y].push_back({x, cost});
    }

    f[1] = 1;

    for (int i = 0; i < mat[1].size(); ++i) {
        q.push({-mat[1][i].second, {1, mat[1][i].first}});
    }

    while (!q.empty()) {
        int cost = q.top().first;
        int from = q.top().second.first;
        int to = q.top().second.second;
        q.pop();

        if (f[to] == 1) {
            continue;
        }

        sir.push_back({from, to});
        suma += cost;
        f[to] = 1;

        for (int i = 0; i < mat[to].size(); ++i) {
            if (f[mat[to][i].first] == 1) {
                continue;
            }

            q.push({-mat[to][i].second, {to, mat[to][i].first}});
        }
    }

    fout << -suma << "\n" << n - 1 << "\n";

    for (int i = 0; i < sir.size(); ++i) {
        fout << sir[i].first << " " << sir[i].second << "\n";
    }

    return 0;
}
