#include <bits/stdc++.h>


using namespace std;



const int len = 100005;

int n, m, x, y, cnt;

vector<int> g[len], gt[len], sol[len], v;

bitset<len> seen;



void dfs1(int curr) {

    seen[curr] = true;

    for (auto& it : g[curr])

        if (!seen[it])

            dfs1(it);

    v.push_back(curr);

}



void dfs2(int curr) {

    seen[curr] = true;

    for (auto& it : gt[curr])

        if (!seen[it])

            dfs2(it);

    sol[cnt].push_back(curr);

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

        if (!seen[i])

            dfs1(i);



    for (auto& it : v)

        seen[it] = false;



    reverse(v.begin(), v.end());

    for (auto& it : v)

        if (!seen[it]) {

            cnt++;

            dfs2(it);

        }



    cout << cnt << "\n";

    for (int i = 1; i <= cnt; i++) {

        for (auto& it : sol[i])

            cout << it << " ";

        cout << "\n";

    }

}
