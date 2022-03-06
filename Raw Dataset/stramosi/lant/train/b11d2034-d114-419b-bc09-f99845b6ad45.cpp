#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pld = pair<ld, ld>;

const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862;
const int inf_int = 1e9 + 5;
const ll inf_ll = 1e18 + 5;
const int NMax = 3e5 + 5;
const int dx[] = {-1,0,0,+1}, dy[] = {0,-1,+1,0};
const double EPS = 1e-8;

int ans[NMax];
bool vis[NMax];
vector<int> stk;
vector<pii> query[NMax];
vector<int> adj[NMax];

void dfs(int node) {

    for (pii p : query[node]) {
        int pth = p.first, idx = p.second;
        if (pth > (int)stk.size()) {
            ans[idx] = 0;
        }
        else {
            pth = (int)stk.size() - pth;
            ans[idx] = stk[pth];
        }
    }

    stk.push_back(node);

    for (int nxt : adj[node]) {
        dfs(nxt);
    }

    stk.pop_back();
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        int dad;
        cin >> dad;
        adj[dad].push_back(i);
    }

    for (int i = 1; i <= M; ++i) {
        int node, pth;
        cin >> node >> pth;
        query[node].push_back({pth, i});
    }

    dfs(0);

    for (int i = 1; i <= M; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
