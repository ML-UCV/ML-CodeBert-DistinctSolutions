#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

struct Point{
  int x, y;
};

const double inf = 4000000000.0;

double dist(const Point &A, const Point &B) {
  return sqrt((1ll * A.x - B.x) * (A.x - B.x) + (1ll * A.y - B.y) * (A.y - B.y));
}

double solve_median(int m, double d, int l, int r, vector<Point> &p_y, int x) {
  vector<Point> v;
  for (int i = l; i <= r; ++i)
    if (abs(x - p_y[i].x) <= d)
      v.push_back(p_y[i]);
  for (int i = 0; i < v.size(); ++i)
    for (int j = i + 1; j < v.size() && j <= i + 5; ++j) {
      d = min(d, dist(v[i], v[j]));
    }
  return d;
}

double solve(int l, int r, vector<Point> &p_x, vector<Point> &p_y) {
  if (l >= r)
    return inf;
  if (r - l + 1 == 2) {
    if (p_y[l].y > p_y[r].y)
      swap(p_y[l], p_y[r]);
    return dist(p_y[l], p_y[r]);
  }
  int m = (l + r) / 2;
  double min_left = solve(l, m, p_x, p_y);
  double min_right = solve(m + 1, r, p_x, p_y);
  double d = min(min_left, min_right);
  vector<Point> v(r - l + 1);
  merge(p_y.begin() + l, p_y.begin() + m + 1, p_y.begin() + m + 1, p_y.begin() + r + 1, v.begin(),
      [](const Point &A, const Point &B) -> bool {
        return A.y < B.y;
      });
  copy(v.begin(), v.end(), p_y.begin() + l);
  d = min(d, solve_median(m, d, l, r, p_y, p_x[m].x));
  return d;
}

int main() {
  ifstream cin("cmap.in");
  ofstream cout("cmap.out");

  int n;
  cin >> n;
  vector<Point> p_x(n), p_y(n);
  for (int i = 0; i < n; ++i) {
    cin >> p_x[i].x >> p_x[i].y;
  }
  sort(p_x.begin(), p_x.end(), [](const Point &A, const Point &B) -> bool {
        return A.x < B.x;
      });
  copy(p_x.begin(), p_x.end(), p_y.begin());
  double ans = solve(0, n - 1, p_x, p_y);
  cout << fixed << setprecision(6) << ans << "\n";
  return 0;
}
