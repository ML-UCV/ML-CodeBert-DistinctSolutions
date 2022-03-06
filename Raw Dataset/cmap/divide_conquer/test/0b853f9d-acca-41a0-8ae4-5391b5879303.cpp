#include <bits/stdc++.h>



using namespace std;

struct point {
    long long x, y;
} P[100002];

auto cmp = [](int a, int b) -> bool { return P[a].y < P[b].y; };

long long dist2(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

long long find_min_dist(int a, int b, vector<int> &points_by_y) {
    int i, j;
    long long min_dist = LONG_LONG_MAX;

    if (b - a + 1 <= 3) {
        for (i = a; i <= b; i++) {
            for (j = i + 1; j <= b; j++)
                min_dist = min(min_dist, dist2(P[i], P[j]));
            points_by_y.push_back(i);
        }
        sort(points_by_y.begin(), points_by_y.end(), cmp);
    } else {

        int m = (a + b) >> 1;
        vector<int> left, right, median_points;
        min_dist = min(find_min_dist(a, m, left), find_min_dist(m + 1, b, right));

        points_by_y.resize(b - a + 1);
        merge(left.begin(), left.end(), right.begin(), right.end(), points_by_y.begin(), cmp);
        for (int p : points_by_y)
            if ((P[p].x - P[m].x) * (P[p].x - P[m].x) <= min_dist)
                median_points.push_back(p);

        for (i = 0; i < median_points.size(); i++)
            for (j = 1; j <= 7; j++)
                if (i + j < median_points.size())
                    min_dist = min(min_dist, dist2(P[median_points[i]], P[median_points[i + j]]));
    }

    return min_dist;
}

int main() {
    ifstream fin("cmap.in");
    ofstream fout("cmap.out");

    int n;
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> P[i].x >> P[i].y;

    sort(P + 1, P + n + 1, [](const point &a, const point &b) -> bool { return a.x < b.x; });
    vector<int> v;
    fout << fixed << setprecision(6) << sqrt((double) find_min_dist(1, n, v));

    return 0;
}
