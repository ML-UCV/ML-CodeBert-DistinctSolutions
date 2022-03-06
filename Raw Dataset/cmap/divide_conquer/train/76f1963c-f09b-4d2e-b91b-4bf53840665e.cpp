#include <bits/stdc++.h>

using namespace std;

struct point {
    long long x, y;
} p[100005];

double dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double closest_points(point *p, int a, int b, vector<int> &v) {
    int i, j;
    double Min = DBL_MAX;
    auto cmp = [&](int x, int y) -> bool { return p[x].y < p[y].y; };

    if (b - a + 1 <= 3) {
        v.clear();
        for (i = a; i <= b; i++) {
            for (j = i + 1; j <= b; j++)
                Min = min(Min, dist(p[i], p[j]));

            v.push_back(i);
        }
        sort(v.begin(), v.end(), cmp);

    } else {
        int m = (a + b) >> 1;

        vector<int> st(m - a + 1), dr(b - m), band;
        double q = closest_points(p, a, m, st);
        double w = closest_points(p, m + 1, b, dr);

        double xd = (p[m].x + p[m + 1].x) / 2;
        double d = min(q, w);
        Min = d;

        merge(st.begin(), st.end(), dr.begin(), dr.end(), v.begin(), cmp);


        for (auto &e: v)
            if (fabs(p[e].x - xd) <= d) band.push_back(e);


        for (i = 0; i < band.size(); i++)
            for (j = i + 1; j < min(i + 8, (int) band.size()); j++)
                Min = min(Min, dist(p[band[i]], p[band[j]]));
    }

    return Min;
}

int main() {
    freopen("cmap.in", "r", stdin);
    freopen("cmap.out", "w", stdout);

    int n, i;
    scanf("%i", &n);
    for (i = 1; i <= n; i++)
        scanf("%lld%lld", &p[i].x, &p[i].y);


    sort(p + 1, p + n + 1, [](point &a, point &b) -> bool { return a.x < b.x; });

    vector<int> v(n);
    printf("%.8lf", closest_points(p, 1, n, v));
    return 0;
}
