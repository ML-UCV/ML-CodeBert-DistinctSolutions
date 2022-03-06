#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmap.in"); ofstream fout ("cmap.out");




const int nmax = 1e5;

pair<int, int> v[nmax + 1], p[nmax + 1];

double dist (pair<int, int> a, pair<int, int> b) {
    return sqrt((double)(a.first - b.first) * (a.first - b.first) + (double)(a.second - b.second) * (a.second - b.second));
}

bool cmp (pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

double solve (int st, int dr) {
    if (dr - st + 1 <= 3) {
        sort(v + st, v + dr + 1, cmp);

        double ans = INFINITY;
        for (int i = st; i <= dr; ++ i)
            for (int j = i + 1; j <= dr; ++ j)
                ans = min(ans, dist(v[i], v[j]));
        return ans;
    }

    int mij = (st + dr) / 2;
    int Xmij = v[mij].first;
    double ans = min(solve(st, mij), solve(mij + 1, dr));


    int ind = st;
    int i = st, j = mij + 1;
    while (i <= mij && j <= dr) {
        if (v[i].second < v[j].second)
            p[ind ++] = v[i ++];
        else
            p[ind ++] = v[j ++];
    }

    for (; i <= mij; ++ i) p[ind ++] = v[i];
    for (; j <= dr; ++ j) p[ind ++] = v[j];

    for (int i = st; i <= dr; ++ i)
        v[i] = p[i];


    ind = 0;
    for (int i = st; i <= dr; ++ i)
        if (fabs(v[i].first - Xmij) < ans)
            p[ind ++] = v[i];


    for (int i = 0; i < ind; ++ i)
        for (int j = i + 1; j <= i + 7 && j < ind; ++ j)
            ans = min(ans, dist(p[i], p[j]));
    return ans;
}

int main () {
    int n;
    fin >> n;

    for (int i = 1; i <= n; ++ i)
        fin >> v[i].first >> v[i].second;

    fout << setprecision(8) << fixed;

    sort(v + 1, v + n + 1);
    fout << solve(1, n) << "\n";

    fin.close();
    fout.close();
    return 0;
}
