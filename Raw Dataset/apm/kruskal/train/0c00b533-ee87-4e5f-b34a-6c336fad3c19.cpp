#include <bits/stdc++.h>
using namespace std;



vector <tuple<int,int,int>> v;

vector<pair<int, int>> ans;

vector <int> ind;

int n, m, cost;



int root(int x) {

    if(ind[x] == x) {

        return x;

    }

    return (ind[x] = root(ind[x]));

}



void fabricaDeUnire(int x, int y) {

    ind[ind[y]] = ind[x];

}



bool cmp(const tuple <int,int,int> & x,const tuple <int,int,int> & b) {

    return (get<2>(x) < get<2>(b));

}



int main() {

    freopen("apm.in", "r", stdin);

    freopen("apm.out", "w", stdout);



    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {

        int x, y, cost;

        scanf("%d%d%d", &x, &y, &cost);

        v.emplace_back(x - 1, y - 1, cost);

    }

    sort(v.begin(), v.end(), cmp);



    for(int i = 0; i < n; ++i) {

        ind.push_back(i);

    }



    for(int i = 0; i < m; i++) {

        int x = get<0>(v[i]);

        int y = get<1>(v[i]);

        if(root(x) != root(y)) {

            cost += get<2>(v[i]);

            fabricaDeUnire(x, y);

            ans.push_back({x, y});

        }

    }



    printf("%d\n%d\n", cost, n - 1);

    for (int i = 0; i < ans.size(); ++i) {

        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);

    }

    return 0;

}
