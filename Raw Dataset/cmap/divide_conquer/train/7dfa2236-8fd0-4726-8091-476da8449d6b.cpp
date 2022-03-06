#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ifstream fin("cmap.in");
ofstream fout("cmap.out");

const ll INF = 1e18;

vector < pair < ll, ll > > points;
vector < pair < ll, ll > > strip;

bool cmp(const pair < ll, ll > &a, const pair < ll, ll > &b) {
    return a.second < b.second;
}
ll getDistance(const pair < ll, ll > &a, const pair < ll, ll > &b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
ll Solve(int s, int e) {
    if(e - s <= 3) {
        ll dist = INF;
        for(int i = s; i < e; ++i) {
            for(int j = i + 1; j < e; ++j) {
                dist = min(dist, getDistance(points[i], points[j]));
            }
        }
        return dist;
    }
    int mid = (s + e) / 2;
    ll dist = min(Solve(s, mid), Solve(mid, e));

    int idx = 0;
    for(int i = s; i < e; ++i) {
        if(abs(points[mid].first - points[i].first) < dist) {
            strip[idx++] = points[i];
        }
    }

    sort(strip.begin(), strip.begin() + idx, cmp);

    for(int i = 0; i < idx; ++i) {
        for(int j = i + 1; j < idx && j - i <= 7; ++j) {
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
    fout << fixed << setprecision(10) << sqrtl((ld)Solve(0, n));
    return 0;
}
