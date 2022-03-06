#include <bits/stdc++.h>

using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");

const int NMAX = 30005;
vector<pair<int, int> > g[NMAX];
queue<pair<int, int> > q;
bool visited[NMAX];

int main() {
    ios::sync_with_stdio(false);
    int n, m, x, y;
    in >> n >> m >> x >> y;
    for (int i = 1; i <= m; i ++) {
        int a, b, c;
        in >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    q.push({x, 0});
    visited[x] = 1;
    while (q.size()) {
        auto s = q.front();
        q.pop();
        if(s.first == y) {
            out << s.second;
            return 0;
        }
        for(auto i : g[s.first]) {
            if(!visited[i.first]) {
                visited[i.first] = 1;
                int aux = s.second;
                if(i.first < s.first)
                    aux -= i.second;
                else
                    aux += i.second;
                q.push({i.first, aux});
            }
        }
    }
    return 0;
}
