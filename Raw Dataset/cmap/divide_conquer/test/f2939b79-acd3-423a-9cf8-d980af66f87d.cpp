#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



struct point{

 int x, y;

};



int n;

vector<point> points;

vector<point> points2;



void in(){

 ifstream fin("cmap.in");

 fin >> n;

 for (int i = 0; i < n; i++)

 {

  point p;

  fin >> p.x >> p.y;

  points.push_back(p);

 }

}



bool lessX(point a, point b){

 return a.x < b.x;

}



bool lessY(point a, point b){

 return a.y < b.y;

}



double dist(point a, point b){

 return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));

}





double minDist(int s, int e){

 if (e - s == 1){



  return dist(points[s], points[e]);

 }

 else if (e - s == 2){



  double d12 = dist(points[s], points[s + 1]);

  double d23 = dist(points[s + 1], points[e]);

  double d13 = dist(points[s], points[e]);



  return min(d12, min(d23, d13));

 }

 else{

  int mid = (e + s) / 2;

  double d = min(minDist(s, mid), minDist(mid + 1, e));



  vector<point> close;



  int i = mid;

  while (i >= s && points[mid + 1].x - points[i].x < d){

   close.push_back(points[i]);

   i--;

  }



  i = mid + 1;

  while (i <= e && points[i].x - points[mid].x <= d){

   close.push_back(points[i]);

   i++;

  }

  sort(close.begin(), close.end(), lessY);



  if (close.size() > 0){





   for (int i = 0; i < close.size(); i++)

   {

    for (int j = i+1; j < min(i + 8, (int)close.size()); j++)

    {

     if (abs(close[i].y - close[j].y) <= d){

      d = min(d, dist(close[i], close[j]));

     }

    }

   }

  }
  return d;

 }

}



int main(){

 in();

 points2 = points;

 sort(points.begin(), points.end(), lessX);



 int a = 0, b = n-1;

 double d = minDist(a, b);



 ofstream f("cmap.out");

 f << fixed << setprecision(6) << d;

 return 0;

}
