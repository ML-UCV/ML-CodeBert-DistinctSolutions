#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

ifstream fin("cmap.in");
ofstream fout("cmap.out");

const ld INF = 1e13;

vector < pair < ld, ld > > points;
vector < pair < ld, ld > > strip;

ld getDistance(const pair < ld, ld > &a, const pair < ld, ld > &b) {
    return sqrtl((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
ld Solve(int s, int e) {
    if(e - s <= 3) {
        ld dist = INF;
        for(int i = s; i < e; ++i) {
            for(int j = i + 1; j < e; ++j) {
                dist = min(dist, getDistance(points[i], points[j]));
            }
        }
        return dist;
    }

    int mid = (s + e) / 2;
    ld dist = min(Solve(s, mid), Solve(mid, e));

    int idx = 0;
    for(int i = s; i < e; ++i) {
        if(abs(points[mid].first - points[i].first) < dist) {
            strip[idx++] = points[i];
        }
    }

    sort(strip.begin(), strip.begin() + idx, [&](const pair < ld, ld > &a, const pair < ld, ld > &b) {
        return a.second < b.second;
    });

    for(int i = 0; i < idx; ++i) {
        for(int j = i + 1; j < min(i + 7, idx); ++j) {
            dist = min(dist, getDistance(strip[i], strip[j]));
        }
    }
    return dist;
}

int main() {
    int n; fin >> n;
    points.resize(n); strip.resize(n);
    for(int i = 0; i < n; ++i) {
        fin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());
    fout << fixed << setprecision(10) << Solve(0, n);
    return 0;
}
