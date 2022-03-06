#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const int NMAX = 1e5 + 5;
const long double INF = 1.0 * 1e10;

ifstream cin("cmap.in");
ofstream cout("cmap.out");

pair <int, int> v[NMAX];

bool cmp(pair <int, int> x, pair <int, int> y)
{
    if(x.second == y.second)
        return x.first < y.first;
    else
        return x.second < y.second;
}

long double dist(pair <int, int> x, pair <int, int> y)
{
    return (long double)sqrt(1.0 * (x.first - y.first) * (x.first - y.first) + 1.0 * (x.second - y.second) * (x.second - y.second));
}

vector <pair <int, int>> a;

long double solve(int st, int dr)
{
    if(dr - st + 1 <= 3) {
        long double dmin = INF;
        for(int i = st; i < dr; ++i) {
            for(int j = i + 1; j <= dr; ++j)
                dmin = min(dmin, dist(v[i], v[j]));
        }
        return dmin;
    }
    int med = (st + dr) / 2;
    long double dmin = min(solve(st, med), solve(med + 1, dr));
    a.clear();
    for(int i = st; i <= dr; ++i)
        if(abs(v[med].first - v[i].first) <= dmin) {
            a.emplace_back(v[i]);
        }
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < a.size() - 1; ++i) {
        for(int j = i + 1; j < a.size() && j - i <= 7; ++j) {
            dmin = min(dmin, dist(a[i], a[j]));
        }
    }
    return dmin;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v + 1, v + n + 1);
    cout << fixed << setprecision(6) << solve(1, n) << "\n";
    return 0;
}
