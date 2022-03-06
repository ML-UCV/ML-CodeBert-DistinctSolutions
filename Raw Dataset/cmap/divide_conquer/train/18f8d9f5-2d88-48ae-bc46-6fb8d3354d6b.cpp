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



pair <double, vector <pair <int, int>>> findClosestPair(const int i, const int j) {

   if(i == j) return make_pair(1e16, vector <pair<int, int>>(1, p[i]));

   const int m = (i + j) / 2;

   pair <double, vector <pair <int, int>>> dpLeft = findClosestPair(i, m), dpRight = findClosestPair(m + 1, j);

   double dist = min(dpLeft.first, dpRight.first);

   vector <pair <int, int>> ySorted(dpLeft.second.size() + dpRight.second.size());

   merge(dpLeft.second.begin(), dpLeft.second.end(), dpRight.second.begin(), dpRight.second.end(), ySorted.begin(), sortOrdinate);

   vector <pair <int, int>> strip;

   for (const pair <int, int> &x: ySorted)

      if(abs(p[m].first - x.first) < dist)

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
