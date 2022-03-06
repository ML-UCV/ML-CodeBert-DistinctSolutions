#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <cmath>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



const long long INF = 4e18;



struct point {

 int x, y;

};



int n;

vector<point> p;



bool cmp(point a, point b) {

 if (a.x < b.x)

  return true;

 if (a.x == b.x && a.y < b.y)

  return true;

 return false;

}



bool cmpAux(point a, point b) {

 if (a.y < b.y)

  return true;

 if (a.y == b.y && a.x < b.x)

  return true;

 return false;

}



double dist(point a, point b) {

 long long dx = a.x - b.x;

 long long dy = a.y - b.y;

 return sqrt(dx * dx + dy * dy);

}



double distMin(vector<point>& p, int st, int dp) {



 if (dp - st <= 2) {

  double dmin = INF;



  for (int i = st; i < dp; ++i) {

   for (int j = i + 1; j <= dp; ++j)

    dmin = min(dmin, dist(p[i], p[j]));

  }

  return dmin;

 }



 int mid = (st + dp) / 2;



 double dmin = min(distMin(p, st, mid), distMin(p, mid + 1, dp));

 double D = (p[mid].x + p[mid + 1].x) / 2.0;



 vector<point> aux;



 for (int i = st; i <= dp; ++i)

  if (abs(D - p[i].x) <= dmin)

   aux.push_back(p[i]);



 sort(aux.begin(), aux.end(), cmpAux);



 int n = aux.size();

 for (int i = 0; i < n - 1; i++)

  for (int j = i + 1; j < i + 8 && j < n; j++)

   dmin = min(dmin, dist(aux[i], aux[j]));



 return dmin;

}



int main() {

 fin >> n;

 p.resize(n);



 for (int i = 0; i < n; ++i)

  fin >> p[i].x >> p[i].y;



 sort(p.begin(), p.end(), cmp);



 fout << fixed << setprecision(6) << distMin(p, 0, n - 1);



 return 0;

}
