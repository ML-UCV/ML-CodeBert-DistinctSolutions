#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int DIM = 100005;

int low[DIM], lev[DIM];
bool vis[DIM], ins[DIM];
vector<int> stk, edg[DIM];
vector<vector<int>> ctc;

void dfs(int x) {
    static int ctr = 0;
    low[x] = lev[x] = ++ctr;
    vis[x] = ins[x] = true;
    stk.push_back(x);

    for (int y : edg[x]) {
        if (!vis[y])
            dfs(y);
        if (ins[y])
            low[x] = min(low[x], low[y]);
    }

    if (low[x] == lev[x]) {
        ctc.push_back(vector<int>());
        int y;
        do {
            y = stk.back();
            ins[y] = false; stk.pop_back();
            ctc.back().push_back(y);
        } while (y != x);
    }
}

int main(void) {
    freopen("ctc.in", "r", stdin);
    freopen("ctc.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        edg[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs(i);
    }
    cout << ctc.size() << "\n";
    for (auto ct : ctc) {
       for (int x : ct)
           cout << x << " ";
       cout << "\n";
    }
    return 0;
}
