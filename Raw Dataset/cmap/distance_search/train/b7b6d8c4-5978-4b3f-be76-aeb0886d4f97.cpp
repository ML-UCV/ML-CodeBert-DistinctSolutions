#include <bits/stdc++.h>

using namespace std;

double dist(pair<double, double> &a, pair<double, double> &b)
{
 double dx = b.first - a.first;
 double dy = b.second - a.second;
 return sqrt(dx * dx + dy * dy);
}

double compute_minimum_distance(vector<pair<double, double> >::iterator a,
                             vector<pair<double, double> >::iterator b)
{
 if (b - a <= 1) return numeric_limits<double>::max();
 if (b - a == 2) return dist(*a, *(a + 1));

 vector<pair<double, double> >::iterator m = a + (b - a) / 2;
 double d1 = compute_minimum_distance(a, m);
 double d2 = compute_minimum_distance(m, b);
 double d = min(d1, d2);

 pair<double, double> line1 = make_pair((*m).first - d, 0);
 pair<double, double> line2 = make_pair((*m).first + d, 0);
 auto p = lower_bound(a, m, line1);
 auto q = upper_bound(m, b, line2);
 vector<pair<double, double> > middle_zone;
 for (auto it = p; it != q; ++it) {
  middle_zone.push_back(*it);
 }
 sort(middle_zone.begin(), middle_zone.end(), [](const pair<double, double> &x,
                                                 const pair<double, double> &y) {
  return x.second < y.second;
 });
 for (auto it = middle_zone.begin(); it != middle_zone.end(); ++it) {
  for (int i = 1; i <= 7; ++i) {
   if (it + i == middle_zone.end()) break;
   double dd = dist(*it, *(it + i));
   if (dd < d) d = dd;
  }
 }

 return d;
}

int main()
{
 freopen("cmap.in", "rt", stdin);
 freopen("cmap.out", "wt", stdout);
 int n;
 vector<pair<double, double> > v;

 scanf("%d", &n);
 for (int i = 0; i < n; ++i) {
  double a, b;
  scanf("%lf%lf", &a, &b);
  v.push_back(make_pair(a, b));
 }
 sort(v.begin(), v.end());

 printf("%.7lf\n", compute_minimum_distance(v.begin(), v.end()));

 return 0;
}
