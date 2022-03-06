#include <bits/stdc++.h>
using namespace std;





typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

ifstream fin("apm.in");
ofstream fout("apm.out");

int n, m;
vii G[200010];
vector<bool> visited;
int dist[200010];
int p[200010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, c;
        fin >> x >> y >> c;
        G[x].push_back(make_pair(y, c));
        G[y].push_back(make_pair(x, c));
    }

    for (int i = 1; i <= n; i++) {
        visited.push_back(0);
        dist[i] = INT_MAX;
    }

    int cost_total = 0;
    set<ii> s;
    dist[1] = 0;
    s.insert(make_pair(0, 1));
    p[1] = 0;
    for (int i = 1; i <= n; i++) {
        int node = s.begin()->second;
        int d = s.begin()->first;
        s.erase(s.begin());
        visited[node - 1] = 1;
        cost_total += d;

        for (auto &it : G[node]) {
            int vecin = it.first;
            int cost = it.second;
            if (!visited[vecin - 1] && dist[vecin] > cost) {
                if (dist[vecin] != INT_MAX) {
                    s.erase(s.find(make_pair(dist[vecin], vecin)));
                }
                dist[vecin] = cost;
                s.insert(make_pair(dist[vecin], vecin));
                p[vecin] = node;
            }
        }
    }

    fout << cost_total << "\n" << n - 1 << "\n";

    for (int i = 2; i <= n; i++) {
        fout << i << " " << p[i] << "\n";
    }

    return 0;
}
