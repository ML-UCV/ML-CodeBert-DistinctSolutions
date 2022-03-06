#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>


using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");
int n;

pair<int, int> v1[100003], v2[100003], v[100003];



bool cmp(pair<int, int> a, pair<int, int> b) {

 return (a < b);

}



double dist(pair<int, int> a, pair<int, int> b) {

 return sqrt((double)(a.first - b.first) * (a.first - b.first) +

  (double)(a.second - b.second) * (a.second - b.second));

}



double divide(int x, int y) {

 if (x >= y) {

  return 4e18;

 }



 if (y == x + 1) {

  if (v2[x] > v2[y])

   swap(v2[x], v2[y]);

  return dist(v1[x], v1[y]);

 }



 int mij = (x + y) / 2;

 double maxi = min(divide(x, mij), divide(mij + 1, y));



 merge(v2 + x, v2 + mij + 1, v2 + mij + 1, v2 + y + 1, v);



 int i, j, lim;

 for (i = x; i <= y; ++i)

  v2[i] = v[i - x];



 int poz = 0;

 for (i = x; i <= y; ++i)

  if (abs(v2[i].second - v1[mij].first) <= maxi)

   v[poz++] = v2[i];

 for (i = 0; i < poz; ++i) {

  lim = min(poz, i + 8);

  for (j = i + 1; j < lim; ++j)

   maxi = min(maxi, dist(v[i], v[j]));

 }



 return maxi;

}



int main() {

 int i, x, y;



 f >> n;

 for (i = 1; i <= n; ++i) {

  f >> x >> y;

  v1[i] = make_pair(x, y);

 }



 sort(v1 + 1, v1 + n + 1, cmp);

 for (i = 1; i <= n; ++i)

  v2[i] = make_pair(v1[i].second, v1[i].first);

 g << fixed << setprecision(7) << divide(1, n) << '\n';



 return 0;

}
