#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Point;

long long Solve(vector<Point>::iterator b, vector<Point>::iterator e) {
 auto m = b + (e - b) / 2;
 if(m == b) return 4e18;

 int refX = m->first;
 auto ret = min(Solve(b, m), Solve(m, e));

 static auto cmpY = [](Point a, Point b) {
  return a.second < b.second;
 };
 inplace_merge(b, m, e, cmpY);
 assert(is_sorted(b, e, cmpY));

 vector<Point> red;
 for(auto it = b; it != e; ++it) {
  int dx = refX - it->first;
  if(1LL * dx * dx < ret)
   red.push_back(*it);
 }

 auto j1 = red.begin(), j2 = red.begin();
 for(auto it = red.begin(); it != red.end(); ++it) {
  while(j1 != red.end()) {
   int dy = it->second - j1->second;
   if(dy > 0 && 1LL * dy * dy >= ret)
    ++j1;
   else break;
  }
  while(j2 != red.end()) {
   int dy = j2->second - it->second;
   if(dy < 0 || 1LL * dy * dy < ret)
    ++j2;
   else break;
  }

  assert(j2 - j1 <= 8);

  for(auto jt = j1; jt != j2; ++jt)
   if(jt != it) {
    int dx = it->first - jt->first;
    int dy = it->second - jt->second;
    ret = min(ret, 1LL * dx * dx + 1LL * dy * dy);
   }
 }

 return ret;
}

int main() {
 freopen("cmap.in", "r", stdin);
 freopen("cmap.out", "w", stdout);

 int n;
 cin >> n;

 vector<Point> P(n);
 for(int i = 0; i < n; ++i) {
  cin >> P[i].first >> P[i].second;
 }

 sort(P.begin(), P.end());
 auto ret = Solve(P.begin(), P.end());
 cout << fixed << setprecision(12) << sqrt(ret);
 return 0;
}
