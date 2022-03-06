#include <bits/stdc++.h>


using namespace std;



const int kMaxN = 100005;



int n;

pair <int, int> p[kMaxN];



double pointDist(const pair <int, int> &a, const pair <int, int> &b) {

   return sqrt(1.0 * (a.first - b.first) * (a.first - b.first) +

               1.0 * (a.second - b.second) * (a.second - b.second));

}



bool sortOrdinate(const pair <int, int> &a, const pair <int, int> &b) {

   if(a.second == b.second)

      return a.first < b.first;

   return a.second < b.second;

}



bool sortOnlyAbscissa(const pair <int, int> &a, const pair <int, int> &b) {

   return a.first < b.first;

}



pair <double, vector <pair <int, int>>> findClosestPair(const int i, const int j) {

   if (i > j) return make_pair(1e16, vector <pair <int, int>>());

   auto eqRange = equal_range(p + i, p + j + 1, p[(i + j) / 2], sortOnlyAbscissa);

   double dist = 1e16;

   for (int k = eqRange.first - p + 1; k < eqRange.second - p; k++) dist = min(dist, 1.0 * p[k].second - p[k - 1].second);

   auto dpLeft = findClosestPair(i, eqRange.first - p - 1);

   auto dpRight = findClosestPair(eqRange.second - p, j);

   dist = min(dist, min(dpLeft.first, dpRight.first));

   vector <pair <int, int>> ySorted_0(dpLeft.second.size() + dpRight.second.size());

   merge(dpLeft.second.begin(), dpLeft.second.end(), dpRight.second.begin(), dpRight.second.end(), ySorted_0.begin(), sortOrdinate);

   vector <pair <int, int>> ySorted(ySorted_0.size() + eqRange.second - eqRange.first);

   merge(ySorted_0.begin(), ySorted_0.end(), eqRange.first, eqRange.second, ySorted.begin(), sortOrdinate);

   vector <pair <int, int>> strip;

   for (const pair <int, int> &x: ySorted)

      if (abs(p[(i + j) / 2].first - x.first) < dist)

         strip.push_back(x);

   for(int k = 0; k < strip.size(); k++)

      for(int q = 1; k + q < strip.size() && q < 8; q++)

         dist = min(dist, pointDist(strip[k], strip[k + q]));

   return make_pair(dist, ySorted);

}



int main() {

   freopen("cmap.in", "r", stdin);

   freopen("cmap.out", "w", stdout);

   scanf("%d", &n);

   for (int i = 1; i <= n; i++) scanf("%d %d", &p[i].first, &p[i].second);

   sort(p + 1, p + n + 1);

   printf("%f\n", findClosestPair(1, n).first);

   return 0;

}
