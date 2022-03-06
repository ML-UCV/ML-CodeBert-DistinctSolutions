#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>


using namespace std;



struct point {

 long long x, y;

};



vector<point> points, ypoints, selectedpoints;



bool comp (const point &a, const point &b) {

 if (a.x < b.x)

  return 0;

 if (a.x > b.x)

  return 1;



 if (a.y < b.y)

  return 0;

 if (a.y > b.y)

  return 1;



 return 0;

}





long long euclid_distance(const point &a, const point &b) {

 return (a.x - b. x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);

}





long long min(long long a, long long b) {

 return a < b? a:b;

}







long long divide_et_impera(int left, int right) {

 if (right - left <= 2) {

        if (ypoints[left].x > ypoints[left + 1].x || (ypoints[left].x == ypoints[left + 1].x && ypoints[left].y > ypoints[left + 1].y)) {

            point aux = ypoints[left];

            ypoints[left] = ypoints[left + 1];

            ypoints[left + 1] = aux;

        }



  long long res = euclid_distance(points[left], points[right]);

  if (right - left == 1)

   return res;



  return min(res, min(euclid_distance(points[left], points[left + 1]), euclid_distance(points[left+1], points[right])));

 }



 int mid = (left + right) / 2;

 long long left_res = divide_et_impera(left, mid);

 long long right_res = divide_et_impera(mid+ 1, right);



 long long current_res = min(right_res, left_res);

 long long midx = points[(left + right) / 2].x;



    merge(ypoints.begin() + left, ypoints.begin() + mid + 1, ypoints.begin() + mid + 1, ypoints.begin() + right + 1, selectedpoints.begin(), comp);

    copy(selectedpoints.begin(), selectedpoints.begin() + (right - left + 1), ypoints.begin() + left);



    int selectedpointsno = 0;

    for(int i = left; i<= right; ++i)

        if (abs(ypoints[i].y - midx) <= current_res)

            selectedpoints[selectedpointsno++] = ypoints[i];



    for(int i=0; i<selectedpointsno - 1; ++i)

        for(int j = i+1; j< selectedpointsno && j-i < 8; ++j)

     current_res = min(current_res, euclid_distance(selectedpoints[i], selectedpoints[j]));



 return current_res;

}





int main() {

 ifstream in ("cmap.in");

 ofstream out("cmap.out");



 int n;

 in >> n;

 points.resize(n);

    selectedpoints.resize(n);

 for(int i=0; i<n; ++i)

  in >> points[i].x >> points[i].y;



 sort(points.begin(), points.end(), comp);

 ypoints.resize(n);

 for(int i=0; i<n; ++i) {

        ypoints[i].x = points[i].y;

        ypoints[i].y = points[i].x;

 }

 out << fixed << setprecision(6) << sqrt(divide_et_impera(0, n-1));



 return 0;

}
