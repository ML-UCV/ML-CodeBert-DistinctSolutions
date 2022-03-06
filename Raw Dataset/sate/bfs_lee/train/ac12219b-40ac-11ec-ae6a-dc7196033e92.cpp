#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define F0R(i, a, b) for (int i = a; i >= b; --i)
#define FORd(i, n) for (int i = 0; i < n; ++i)
#define F0Rd(i, n) for (int i = n - 1; i >= 0; --i)
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mxN = 3 * 1e4 + 5;

int N, M, start, finish, dist[mxN]; //dist de la start la restul numerelor de pe axa
vector<pair<int, int>> edges[mxN];
bitset<mxN> inQueue;

ifstream fin("sate.in");
ofstream fout("sate.out");

void search_distances() {
    queue<int> q;
    q.push(start);
    inQueue[start] = true;
    while (!q.empty()) {
        int curr_node = q.front();
        inQueue[curr_node] = true;
        q.pop();
        for (pair<int, int> vecin : edges[curr_node]) {
            if (!inQueue[vecin.first]) {
                if (vecin.first > curr_node) {
                    dist[vecin.first] = dist[curr_node] + vecin.second;
                }
                else {
                    dist[vecin.first] = dist[curr_node] - vecin.second;
                }
                q.push(vecin.first);
            }
        }
    }
}

void solve() {
    fin >> N >> M >> start >> finish;
    while (M--) {
        int x, y, z;
        fin >> x >> y >> z;
        edges[x].push_back(make_pair(y, z));
        edges[y].push_back(make_pair(x, z));
    }
    search_distances();
    fout << dist[finish];
}

int main() {
    fin.tie(0); fout.tie(0);
    ios::sync_with_stdio(0);
    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

//read the question correctly (ll vs int)
//what's the meaning of the problem ? Think outside the BOX !!!
//edge cases ?
//make it simple
//write everything (observations, edge cases, ideas, steps, methods, ...)
