#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>


using namespace std;



ifstream in("cmap.in");

ofstream out("cmap.out");



struct point {

 int x, y;

 double distance(point p) const {

  return sqrt((double)(x - p.x)*(x - p.x) + (double)(y - p.y)*(y - p.y));

 }

};



istream& operator>> (istream& is, point& p) {

 is >> p.x >> p.y;

 return is;

}



int n;

point v[100005];



double caut(int l, int r) {

 if (r - l + 1 == 3) {

  return min(v[l].distance(v[l + 1]), min(v[l].distance(v[r]), v[r].distance(v[l + 1])));

 }

 else if (r - l + 1 == 2) {

  return v[l].distance(v[r]);

 }

 else if (r == l) {

  return 10000000;

 }

 int m = (l + r) / 2;

 double ret = min(caut(l, m), caut(m + 1, r));

 vector<point> middlePoints;

 for (int i = l; i <= r; i++)

  if(abs(v[i].x - v[m].x) <= ret)

   middlePoints.push_back(v[i]);

 sort(middlePoints.begin(), middlePoints.end(), [](const point& l, const point& r) { return l.y < r.y; });

 for (int i = 0; i < middlePoints.size(); i++) {

  for (int j = i - 1; j >= 0 && i - j <= 7; j--) {

   double dist = middlePoints[i].distance(middlePoints[j]);

   ret = min(ret, dist);

  }

  for (int j = i + 1; j < middlePoints.size() && j - i <= 7; j++) {

   double dist = middlePoints[i].distance(middlePoints[j]);

   ret = min(ret, dist);

  }

 }

 return ret;

}



int main() {

 in >> n;

 for (int i = 1; i <= n; i++)

  in >> v[i];

 sort(v + 1, v + n + 1, [](const point& l, const point& r) { return l.x < r.x; });

 out << fixed << setprecision(6) << caut(1, n) << '\n';

}
