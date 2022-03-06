#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;



struct point {

 long x, y;

};



ifstream in("cmap.in");

ofstream out("cmap.out");



vector <point> points, Y;

int n;



void read() {

 in >> n;

 point A;

 for (int i = 1; i <= n; i++) {

  in >> A.x >> A.y;

  points.push_back(A);

  Y.push_back(A);

 }



}



bool operator < (const point& A, const point& B) {

 if (A.x == B.x) {

  if (A.y < B.y) {

   return true;

  }

  return false;

 }

 else if (A.x < B.x) {

  return true;

 }

 return false;

}



bool cmp(const point& A, const point& B) {

 if (A.y == B.y) {

  if (A.x < B.x) {

   return true;

  }

  return false;

 }

 else if (A.y < B.y) {

  return true;

 }

 return false;

}





long double computeDistance(const point& A, const point& B) {



 return sqrt(pow(A.x - B.x, 2.0) + pow(A.y - B.y, 2.0));



}



long double minim(long double d1, long double d2) {

 if (d1 < d2) {

  return d1;

 }

 return d2;

}





long double minnn(long double d1, long double d2, long double d3) {

 long double d4 = minim(d1, d2);

 return minim(d3, d4);

}





long double minn(const vector <point>& arr, int left, int right) {

 if (right - left + 1 == 1) {

  return 0.0;

 }

 else if (right - left + 1 == 2) {

  return computeDistance(arr[left], arr[left + 1]);

 }

 else {

  return minnn(computeDistance(arr[left], arr[left + 1]), computeDistance(arr[left], arr[right]), computeDistance(arr[left + 1], arr[right]));

 }





}



void printValues(const vector <point>& arr) {

 int count = 0;

 for (auto x : arr) {

  cout << count << ".  " << x.x << "\t\t" << x.y << '\n';

  count++;

 }

}



long double divide(int left, int right, const vector <point>& Yy) {

 vector <point> SY, DY, LY;

 int size = right - left + 1;

 long double d = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0;

 if (size < 4) {

  d = minn(points, left, right);

 }

 else {



  int mij = left + (right - left) / 2;



  for (int i = 0; i < Yy.size(); i++) {



   if ((Yy[i].x < points[mij].x) || ((Yy[i].x == points[mij].x) && (Yy[i].y <= points[mij].y))) {

    SY.push_back(Yy[i]);

   }

   else {



    DY.push_back(Yy[i]);

   }

  }





  d1 = divide(left, mij, SY);

  d2 = divide(mij + 1, right, DY);

  d = minim(d1, d2);

  for (int i = 0; i < Yy.size(); i++) {

   if (abs(Yy[i].x - points[mij].x) <= d) {

    LY.push_back(Yy[i]);

   }



  }

  d3 = d, d4 = d;

  for (int i = 0; i < LY.size(); i++) {

   for (int j = i + 1; j < LY.size() && abs(LY[i].y - LY[j].y) < d; j++) {

    d4 = computeDistance(LY[i], LY[j]);

    if (d4 < d3) {

     d3 = d4;

    }

   }

  }

  d = minim(d, d3);



 }

 return d;

}



int main()

{

 read();

 sort(points.begin(), points.end());

 sort(Y.begin(), Y.end(), cmp);

 out << fixed << setprecision(6) << divide(0, n - 1, Y);

 return 0;

}
