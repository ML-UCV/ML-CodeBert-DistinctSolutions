#include <bits/stdc++.h>
using namespace std;

const string problem("cmap");

ifstream fin(problem + ".in");

ofstream fout(problem + ".out");

typedef long long i64;

using PII = pair<i64, i64>;

vector<PII> v;

set<PII> s;

int n;

i64 ys, yd, j(1);

double res(1e18);

inline double Dist(PII a, PII b) {

    return sqrt(1.0 * ((1LL * (a.first - b.first) * (a.first - b.first)) + (1LL * (a.second - b.second) * (a.second - b.second))));

}

int main() {

    ios::sync_with_stdio(false); fin.tie(0); fout.tie(0);

    fin >> n;

    v = vector<PII>(n + 1);

    for (int i = 1; i <= n; ++i)

        fin >> v[i].first >> v[i].second;

    sort(v.begin() + 1, v.end());

    for (int i = 1; i <= n; ++i) {

        while (!s.empty() && (v[i].first - v[j].first) >= res)

            s.erase(s.find({v[j].second, v[j].first})), ++j;

        ys = v[i].second - static_cast<i64>(res) - 1;

        yd = v[i].second + static_cast<i64>(res) + 1;

        auto st = s.lower_bound({ys, 1e9});

        auto dr = s.lower_bound({yd, 1e9});

        for (auto it = st; it != dr; ++it) {

            if (it == s.end())

                break;

            res = min(res, Dist(v[i], {it -> second, it -> first}));

        }

        s.emplace(v[i].second, v[i].first);

    }

    fout << fixed << setprecision(10) << res;

    fin.close(); fout.close(); return 0;

}
