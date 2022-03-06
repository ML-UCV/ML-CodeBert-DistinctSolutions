#include <bits/stdc++.h>

using namespace std;

long long ClosestPair(vector<pair<int, int>> pts) {
    int n = pts.size();
    sort(pts.begin(), pts.end());
    set<pair<int, int>> s;

    long long best_dist = 1e18;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        int d = ceil(sqrt(best_dist));
        while (pts[i].first - pts[j].first >= best_dist) {
            s.erase({pts[j].second, pts[j].first});
            j += 1;
        }

        auto it1 = s.lower_bound({pts[i].second - d, pts[i].first});
        auto it2 = s.upper_bound({pts[i].second + d, pts[i].first});

        for (auto it = it1; it != it2; ++it) {
            int dx = pts[i].first - it->second;
            int dy = pts[i].second - it->first;
            best_dist = min(best_dist, 1LL * dx * dx + 1LL * dy * dy);
        }
        s.insert({pts[i].second, pts[i].first});
    }
    return best_dist;
}

int main() {
    ifstream cin("cmap.in");
    ofstream cout("cmap.out");

    int n; cin >> n;
    vector<pair<int, int>> pts;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        pts.emplace_back(x, y);
    }
    cout << fixed << setprecision(20) << sqrt(ClosestPair(pts)) << endl;
}
