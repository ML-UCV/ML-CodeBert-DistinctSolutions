#include <bits/stdc++.h>


using namespace std;



const int len = 100005;

int n, m, x, y, cnt;

vector<int> g[len], gt[len], sol[len], v;

bitset<len> seen1, seen2;



void dfs1(int node) {

    seen1[node] = true;

    for (auto& next : g[node])

        if (!seen1[next])

            dfs1(next);

    v.push_back(node);

}



void dfs2(int node) {

    seen2[node] = true;

    for (auto& next : gt[node])

        if (!seen2[next])

            dfs2(next);

    sol[cnt].push_back(node);

}



int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);



    freopen("ctc.in", "r", stdin);

    freopen("ctc.out", "w", stdout);



    cin >> n >> m;

    for (int i = 1; i <= m; i++) {

        cin >> x >> y;

        g[x].push_back(y);

        gt[y].push_back(x);

    }



    for (int i = 1; i <= n; i++)

        if (!seen1[i])

            dfs1(i);



    reverse(v.begin(), v.end());

    for (auto& it : v) {

        if (!seen2[it]) {

            cnt++;

            dfs2(it);

        }

    }



    cout << cnt << "\n";

    for (int i = 1; i <= cnt; i++) {

        for (auto& it : sol[i])

            cout << it << " ";

        cout << "\n";

    }

}
