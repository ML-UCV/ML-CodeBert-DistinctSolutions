#include <bits/stdc++.h>

using namespace std;
using Point = complex<long long>;
namespace std {
  bool operator<(const Point a, const Point b) {
    return make_pair(a.real(), a.imag())
      < make_pair(b.real(), b.imag());
  }
}
tuple<long long, Point, Point> ClosestPair(vector<Point> v) {
  assert((int)v.size() > 1);
  sort(v.begin(), v.end(), [&](Point a, Point b) {
    return a.imag() < b.imag();
  });
  set<Point> s; int j = 0;
  tuple<long long, Point, Point> ret{LLONG_MAX, {}, {}};
  for (auto p : v) {
    long long d = 1 + sqrt(get<0>(ret));
    while (v[j].imag() <= p.imag() - d) s.erase(v[j++]);
    auto lo = s.lower_bound(p - d),
         hi = s.upper_bound(p + d);
    for (auto it = lo; it != hi; ++it)
      ret = min(ret, {norm(*it - p), *it, p});
    s.insert(p);
  }
  return ret;
}

int main() {
  ifstream cin("cmap.in");
  ofstream cout("cmap.out");
  int n; cin >> n;
  vector<Point> v(n);
  for (int i = 0; i < n; ++i) {
    int a, b; cin >> a >> b;
    v[i] = {a, b};
  }
  auto d = get<0>(ClosestPair(v));
  cout << fixed << setprecision(20) << sqrt(d) << endl;
  return 0;
}
