#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;



typedef long long ll;

typedef pair < ll, ll > point;

point points[100001], strip[100001];

point aux[100001];

int n, n_strip;



void read() {



 ifstream in("cmap.in");

 ll x, y;

 in >> n;

 for (int i = 1; i <= n; ++i) {



  in >> x >> y;

  points[i] = make_pair(x, y);

 }

 in.close();

}



bool compareX(const point& f, const point& s) {



 if ((f.first < s.first) || (f.first == s.first && f.second < s.second))

  return true;

 return false;

}



bool compareY(const point& f, const point& s) {



 if ((f.second < s.second) || (f.second == s.second && f.first < s.first))

  return true;

 return false;

}



inline ll dist(const point& p1, const point& p2) {



 return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);

}



ll brute_dist(point points[], int left, int right) {



 ll best_dist = LLONG_MAX;

 for (int i = left; i < right; i++)

  for (int j = i + 1; j <= right; j++)

   best_dist = min(best_dist, dist(points[i], points[j]));



 return best_dist;

}



ll min_dist_strip(ll d_min) {



 ll best_dist = d_min;



 for (int i = 1; i < n_strip; i++)

  for (int j = i + 1, k = 1; j <= n_strip && k <= 7; j++, k++)

   best_dist = min(best_dist, dist(strip[i], strip[j]));



 return best_dist;

}



void merge(int x1, int y1, int x2, int y2) {



 int k = 0;

 while (x1 <= y1 && x2 <= y2) {



  if (compareY(points[x1], points[x2]))

   aux[++k] = points[x1++];

  else

   aux[++k] = points[x2++];

 }

 while (x1 <= y1)

  aux[++k] = points[x1++];

 while (x2 <= y2)

  aux[++k] = points[x2++];

}



ll merge_sort(int left, int right) {



 if (right - left < 4) {



  sort(points + left, points + right + 1, compareY);

  return brute_dist(points, left, right);



 }



 int mid = left + (right - left) / 2;

 ll mid_x = points[mid].first;



 ll d1 = merge_sort(left, mid);

 ll d2 = merge_sort(mid + 1, right);

 ll delta = min(d1, d2);





 merge(left, mid, mid + 1, right);



 for (int i = left; i <= right; ++i)

  points[i] = aux[i - left + 1];





 n_strip = 0;



 for (int i = left; i <= right; i++)

  if (abs(points[i].first - mid_x) <= delta)

   strip[++n_strip] = points[i];

 ll d3 = min_dist_strip(delta);

 return min(delta, d3);

}



int main() {



 read();



 sort(points + 1, points + n + 1, compareX);



 ofstream out("cmap.out");

 out << fixed << setprecision(6) << sqrt(merge_sort(1, n)) << "\n";

 out.close();



 return 0;

}
