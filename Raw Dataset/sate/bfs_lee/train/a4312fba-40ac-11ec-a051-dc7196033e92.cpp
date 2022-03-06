#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define in std::cin
#define out std::cout
#else
std::ifstream in("sate.in");
std::ofstream out("sate.out");
#endif

constexpr int N = 3e4 + 1;
std::vector<std::pair<int, int>> g[N];
std::bitset<N> vis;

int bfs(int x, int y) {
    std::queue<std::pair<int, int>> q{{{x, 0}}};
    vis[x] = 1;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        int u = x.first;
        int ud = x.second;
        for (auto x : g[u]) {
            int v = x.first;
            int vd = x.second;
            if (vis[v]) continue;
            vis[v] = 1;
            vd = v > u ? vd : -vd;
            if (v == y) return ud + vd;
            q.push({v, ud + vd});
        }
    }   
}

int main() {
    int n, m;
    int x, y;
    in >> n >> m >> x >> y;
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        in >> u >> v >> d;
        g[u].push_back({v, d});
        g[v].push_back({u, d});
    }
    out << bfs(x, y) << '\n';
}
