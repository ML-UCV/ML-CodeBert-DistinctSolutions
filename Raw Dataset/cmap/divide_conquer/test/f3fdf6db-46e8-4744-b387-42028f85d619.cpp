#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>


using namespace std;



ifstream cin("cmap.in");

ofstream cout("cmap.out");



struct point {

 double x, y;

};



bool cmpX(point a, point b) {

 if (a.x > b.x) return 1;

 return 0;

}



bool cmpY(point a, point b) {

 if (a.y > b.y) return 1;

 return 0;

}



double twoPointsDistance(point a, point b){

 return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));

}



double minDistance(const vector <point> &pt, int left, int right) {



 int separator = (left + right) / 2;

 double delta = 2e9;



 if (right - left > 2)

  delta = min (minDistance(pt, left, separator), minDistance(pt, separator + 1, right));



 else

  for(int i = left; i < right; ++i)

   for (int j = i + 1; j <= right; ++j)

    delta = min(delta, twoPointsDistance(pt[i], pt[j]));





 vector <point> eligiblePoints;

 for (int i = left; i <= right; ++i)

  if (abs(pt[i].x - pt[separator].x) < delta)

   eligiblePoints.push_back(pt[i]);



 sort(eligiblePoints.begin(), eligiblePoints.end(), cmpY);



 int n = eligiblePoints.size();

 for (int i = 0; i < n; ++i) {



  int m = min(n, i + 8);

  for (int j = i + 1; j < m; ++j)

   delta = min(delta, twoPointsDistance(eligiblePoints[i], eligiblePoints[j]));

 }



 return delta;

}





int main()

{

 int n;

 vector <point> pt;



 cin >> n;

 for (int i = 0; i < n; ++i) {

  point x;

  cin >> x.x >> x.y;

  pt.push_back(x);

 }

 sort(pt.begin(), pt.end(), cmpX);



 double minimumDistance = minDistance(pt, 0, n - 1);



 cout << fixed << setprecision(6) << minimumDistance;



}
