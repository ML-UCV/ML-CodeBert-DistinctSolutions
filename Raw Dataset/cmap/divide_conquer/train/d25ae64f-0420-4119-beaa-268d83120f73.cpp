#include <bits/stdc++.h>


using namespace std;

const int N = 1e5;

const double EPS = 0.00000001;

struct Point {

    int x;

    int y;

    bool operator < (const Point &p) const {

        return y < p.y;

    }

};



Point a[1 + N];



bool comp (Point a, Point b) {

    return a.x < b.x;

}



double sq (double x) {

    return x * x;

}



double dist (Point a, Point b) {

    return sqrt (sq (a.x - b.x) + sq (a.y - b.y));

}



double solve (int l, int r) {

    int mid = (l + r) / 2;

    if (r - l <= 4) {

        double ans = dist (a[l], a[l + 1]);

        for (int i = l; i <= r; i++) for (int j = i + 1; j <= r; j++) ans = min (ans, dist (a[i], a[j]));

        return ans;

    }

    double ans = min (solve (l, mid), solve (mid + 1, r));

    vector <Point> v;

    for (int i = l; i <= r; i++) if (abs (a[i].y - a[mid].y) - ans < -EPS) v.push_back (a[i]);

    sort (v.begin (), v.end (), comp);

    for (int i = 0; i < v.size (); i++) for (int j = i + 1; j < min ((int)v.size (), i + 10); j++) ans = min (ans, dist (v[i], v[j]));

    return ans;

}



int main() {

    freopen ("cmap.in", "r", stdin);

    freopen ("cmap.out", "w", stdout);

    ios::sync_with_stdio (false);

    cin.tie (0); cout.tie (0);

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;

    sort (a + 1, a + n + 1);

    cout << fixed << setprecision (8) << solve (1, n) << "\n";

    return 0;

}
