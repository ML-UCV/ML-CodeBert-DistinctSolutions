#include <bits/stdc++.h>

using namespace std;
using Point = complex<double>;

const double PI = 4.0 * atan(1.0);
const double EPS = 1e-9;

double dot(Point a, Point b) { return (conj(a) * b).real(); }
double cross(Point a, Point b) { return (conj(a) * b).imag(); }
double det(Point a, Point b, Point c) {
  return cross(b - a, c - a); }
double dist(Point a, Point b) { return abs(b - a); }
Point perp(Point a) { return {-a.imag(), a.real()}; }
Point rotate_ccw(Point a, double theta) {
  return a * polar(1.0, theta); }

namespace std {
  bool operator<(const Point a, const Point b) {
    return make_pair(a.real(), a.imag()) <
      make_pair(b.real(), b.imag());
  }
}
tuple<double, Point, Point> ClosestPair(vector<Point> v) {
  assert((int)v.size() > 1);
  sort(v.begin(), v.end(), [&](Point a, Point b) {
    return a.imag() < b.imag();
  });
  set<Point> s; int j = 0;
  tuple<double, Point, Point> ret{4e18, {}, {}};
  for (auto p : v) {
    double d = 1 + sqrt(get<0>(ret));
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
    double a, b; cin >> a >> b;
    v[i] = {a, b};
  }
  auto d = get<0>(ClosestPair(v));
  cout << fixed << setprecision(20) << sqrt(d) << endl;
  return 0;
}
