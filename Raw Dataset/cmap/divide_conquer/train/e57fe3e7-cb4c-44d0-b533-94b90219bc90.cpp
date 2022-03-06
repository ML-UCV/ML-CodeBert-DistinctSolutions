#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>



using namespace std;

long long INF = 4e18;
vector <pair<long long, long long> > v, x, y;
int N;

long long dist(pair <long long, long long> a, pair <long long, long long> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

long long solve(int st, int dr) {
    if (st >= dr - 1) return INF;
    if (dr - st == 2) {
        if (y[st] > y[st + 1]) {
            swap(y[st], y[st + 1]);
        }
        return dist(x[st], x[st + 1]);
    }
    int mij = (st + dr) / 2;
    long long ret = min(solve(st, mij), solve(mij, dr));
    merge(y.begin() + st, y.begin() + mij, y.begin() + mij, y.begin() + dr, v.begin());
    copy(v.begin(), v.begin() + (dr - st), y.begin() + st);
    int nr = 0;
    for (int i=st; i<dr; ++i) if (abs(y[i].second - x[mij].first) <= ret) {
        v[nr++] = y[i];
    }
    for (int i=0; i<nr-1; ++i) {
        for (int j=i+1; j<nr && j<i+8; ++j) {
            ret = min(ret, dist(v[i], v[j]));
        }
    }
    return ret;
}

void closest_points() {
    sort(x.begin(), x.end());
    y.resize(N), v.resize(N);
    for (int i = 0; i < (int) x.size(); ++ i) {
        y[i] = make_pair(x[i].second, x[i].first);
    }
    printf("%.10lf\n",sqrt(solve(0, N)));
}

int main() {
    freopen("cmap.in","r",stdin);
    freopen("cmap.out","w",stdout);
    scanf("%d",&N);
    x.resize(N);
    for (int i = 0; i < N; ++ i) {
        scanf("%lld%lld",&x[i].first,&x[i].second);
    }
    closest_points();
    return 0;
}
