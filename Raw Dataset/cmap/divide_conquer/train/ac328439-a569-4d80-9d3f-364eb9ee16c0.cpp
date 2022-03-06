#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



struct point {

 double x, y;

};



int p;

vector<point>v;

double a, b;



double dist(point a, point b)

{

 return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));

}



bool cmpX(point a, point b)

{

 if (a.x == b.x)

  return a.y < b.y;

 return a.x < b.x;

}



bool cmpY(point a, point b)

{

 if (a.y == b.y)

  return a.x < b.x;

 return a.y < b.y;

}



double bruteDistance(vector<point> v)

{

 double d = 2000000000;

 for (int i = 0; i < v.size() - 1; i++)

  for (int j = i + 1; j < v.size(); j++)

   d = min(d, dist(v[i], v[j]));

 return d;

}



double calculateStrip(vector<point> strip, double d)

{

 sort(strip.begin(), strip.end(), cmpY);

 double mi = 2000000000;

 for (int i = 0; i < strip.size() - 1; i++)

  for (int j = i + 1; j < strip.size() && (abs(strip[j].y - strip[i].y) < mi); j++)

   mi = min(mi, dist(strip[i], strip[j]));

 return mi;

}



double closest(vector<point> v)

{

 int n = v.size()-1;

 if (n <= 3)

  return bruteDistance(v);

 int mid = n / 2;

 vector<point>st(v.begin(), v.begin() + mid);

 vector<point>dr(v.begin() + mid+1, v.end());

 double dLeft = closest(st);

 double dRight = closest(dr);

 double d = min(dLeft, dRight);

 vector<point>strip;

 point Middle(v[mid]);

 for (int i = 0; i < v.size(); i++)

  if (abs(Middle.x - v[i].x) < d)

   strip.push_back(v[i]);

 return min(d, calculateStrip(strip, d));

}



double closestDistance(vector<point> v)

{

 sort(v.begin(), v.end(), cmpX);

 return closest(v);

}



void read()

{

 fin >> p;

 while (p--)

 {

  point temp;

  fin >> temp.x >> temp.y;

  v.push_back(temp);

 }

}



void solve()

{

 fout << setprecision(12) << fixed << closestDistance(v) << "\n";

}





int main()

{

 read();

 solve();

 return 0;

}
