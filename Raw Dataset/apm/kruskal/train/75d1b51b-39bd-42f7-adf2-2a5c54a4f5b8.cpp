#include <bits/stdc++.h>


using namespace std;



const int len = 400005;

int m, n, parent[len], level[len], cost;

vector<pair<int, int> > sol;



struct edge {

    int x, y, c;

} e[len];



bool cmp(edge a, edge b) {

    return a.c < b.c;

}



void make_set(int k) {

    parent[k] = k;

    level[k] = 1;

}



int find_set(int k) {

    if (parent[k] == k)

        return k;

    return parent[k] = find_set(parent[k]);

}



void union_sets(int x, int y) {

    x = find_set(x);

    y = find_set(y);

    if (x != y) {

        if (level[x] < level[y])

            swap(x, y);

        parent[y] = x;

        if (level[x] == level[y])

            level[x]++;

    }

}



int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);



    freopen("apm.in", "r", stdin);

    freopen("apm.out", "w", stdout);



    cin >> n >> m;

    for (int i = 0; i < m; i++)

        cin >> e[i].x >> e[i].y >> e[i].c;

    sort(e, e + m, cmp);

    for (int i = 0; i < m; i++)

        make_set(i);



    for (int i = 0; i < m && !sol.empty() < n; i++)

        if (find_set(e[i].x) != find_set(e[i].y)) {

            cost += e[i].c;

            union_sets(e[i].x, e[i].y);

            sol.push_back({e[i].x, e[i].y});

        }



    cout << cost << "\n" << n - 1 << "\n";

    for (auto& it : sol)

        cout << it.first << " " << it.second << "\n";

}
