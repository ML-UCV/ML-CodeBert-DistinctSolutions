#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>






using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



struct point {

 int x, y;

};



vector<point> vec;

point p, q;

double d;



bool cmpX(point& a, point& b) {

 if (a.x == b.x) return a.y < b.y;

 return a.x < b.x;

}



bool cmpY(point& a, point& b) {

 if (a.y == b.y) return a.x < b.x;

 return a.y < b.y;

}



double dist(point a, point b) {

 long long int x = (long long int)a.x - (long long int)b.x;

 long long int y = (long long int)a.y - (long long int)b.y;

 x *= x;

 y *= y;

 return sqrt(x + y);

}



double bruteForce(vector<point>& strip, double d) {

 double dmin = d;

 for (int i = 0;i < strip.size();++i)

  for (int j = i + 1;j < strip.size() && (double)strip[j].y - (double)strip[i].y < dmin;++j) {

   double tmp = dist(strip[i], strip[j]);

   if (tmp < dmin) dmin = tmp;

  }

 return dmin;

}



void merge(int i, int j, int k, vector<point>& vec) {

 vector<point> res;

 int u = i, v = j + 1;

 while (u <= j && v <= k) {

  if (cmpY(vec[u], vec[v])) {

   res.push_back(vec[u]);

   ++u;

  }

  else {

   res.push_back(vec[v]);

   ++v;

  }

 }

 while (u <= j) {

  res.push_back(vec[u]);

  ++u;

 }

 while (v <= k) {

  res.push_back(vec[v]);

  ++v;

 }

 for (u = i;u <= k;++u)

  vec[u] = res[u-i];

}



double closestPairDist(vector<point>& vec, int i, int j,vector<point>& sorted) {

 if (i >= j) {

  if (i == j) sorted[i] = vec[i];

  return 1e17;

 }

 int m = (i + j) / 2;

 double d1 = closestPairDist(vec, i, m, sorted);

 double d2 = closestPairDist(vec, m + 1, j, sorted);

 double d = min(d1, d2);

 merge(i, m, j, sorted);

 vector<point> strip;

 for (int k = i;k <= j;++k)

  if (abs(sorted[k].x - vec[m].x) < d)

   strip.push_back(sorted[k]);

 d = bruteForce(strip, d);

 return d;

}



double closestPair(vector<point>& vec) {

 sort(vec.begin(), vec.end(), cmpX);

 vector<point> sorted;

 sorted.resize(vec.size());

 return closestPairDist(vec, 0, vec.size() - 1, sorted);

}



int main() {

 int n;

 fin >> n;

 int x, y;

 while (n--) {

  fin >> x >> y;

  vec.push_back({ x,y });

 }

 fout << fixed << setprecision(6);

 fout<<closestPair(vec);

 return 0;

}
