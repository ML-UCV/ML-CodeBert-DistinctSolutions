#include <fstream>
#include <vector>
#include <queue>
using namespace std;
const int NMAX = 30000;
int n, m, x, y, a, b, c, ans;
vector<pair<int, int>> g[NMAX + 1];
queue<int> q;
int dist[NMAX + 1];
int Solve() {
    q.push(x);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        vector<pair<int, int>>::iterator it;
        for(it = g[node].begin(); it != g[node].end(); ++it) {
            pair<int, int> sat = *it;
            if(!dist[sat.first]) {
                dist[sat.first] = sat.second + dist[node];
                q.push(sat.first);
            }
        }
    }
    return 0;
}
int main() {
    ifstream cin("sate.in");
    ofstream cout("sate.out");
    cin >> n >> m >> x >> y;
    for(int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, -c));
    }
    Solve();
    cout << dist[y] << "\n";
    return 0;
}
