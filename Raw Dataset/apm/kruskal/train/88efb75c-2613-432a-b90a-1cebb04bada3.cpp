#include <bits/stdc++.h>


using namespace std;



const int len = 400005;

int m, n, parent[len], level[len], cost;

vector<pair<int, int> > sol;



struct Edge {

    int x, y, c;

}edge[len];



bool compare(Edge x, Edge y) {

    return x.c < y.c;

}



void make_set(int k) {

    parent[k] = k;

    level[k] = 0;

}



int find_set(int k) {

    if (parent[k] == k)

        return k;

    return parent[k] = find_set(parent[k]);

}



int union_sets(int x, int y) {

    x = find_set(x);

    y = find_set(y);

    if (x != y) {

        if (level[x] < level[y])

            swap(x, y);

        parent[x] = y;

        if (level[x] == level[y])

            level[x]++;

    }

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);



    freopen("apm.in", "r", stdin);

    freopen("apm.out", "w", stdout);



    cin >> n >> m;

    for (int i = 0; i < m; i++)

        cin >> edge[i].x >> edge[i].y >> edge[i].c;

    sort(edge, edge + m, compare);

    for (int i = 0; i < n; i++)

        make_set(i);



    for (int i = 0; i < m && sol.size() < n; i++)

        if (find_set(edge[i].x) != find_set(edge[i].y)) {

            cost += edge[i].c;

            union_sets(edge[i].x, edge[i].y);

            sol.push_back({edge[i].x, edge[i].y});

        }



    cout << cost << "\n" << n - 1 << "\n";

    for (int i = 0; i < n - 1; i++)

        cout << sol[i].first << " " << sol[i].second << "\n";

}
