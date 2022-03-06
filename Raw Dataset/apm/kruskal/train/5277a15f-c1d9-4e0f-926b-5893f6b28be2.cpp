#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



const int MMAX = 4e5 + 5;

const int NMAX = 1e5 + 5;



struct edge {

    int x, y, c;

};

edge e[MMAX];

int h[NMAX], dad[NMAX], cnt, ans[NMAX], sum;



bool cmp(const edge &a, const edge &b) {

    return a.c < b.c;

}



void Union(int x, int y) {

    if(h[x] > h[y]) {

        dad[y] = x;

    } else {

        dad[x] = y;

        if(h[x] == h[y]) {

            h[y]++;

        }

    }

}



int Find(int x) {

    int root = x;

    while(dad[root] != root) {

        root = dad[root];

    }

    int y = x;

    while(y != root) {

        int t = dad[y];

        dad[y] = root;

        y = t;

    }

    return root;

}



int main()

{

    int n, m;

    f >> n >> m;

    for(int i = 1; i <= m; i++) {

        f >> e[i].x >> e[i].y >> e[i].c;

    }

    sort(e + 1, e + m + 1, cmp);

    for(int i = 1; i <= n; i++) {

        dad[i] = i;

        h[i] = 1;

    }

    for(int i = 1; i <= m && cnt < n - 1; i++) {

        int p = Find(e[i].x);

        int q = Find(e[i].y);

        if(p != q) {

            cnt++;

            sum += e[i].c;

            ans[cnt] = i;

            Union(p, q);

        }

    }

    g << sum << '\n';

    g << n - 1 << '\n';

    for(int i = 1; i <= n - 1; i++) {

        g << e[ans[i]].x << ' ' << e[ans[i]].y << '\n';

    }

    return 0;

}
