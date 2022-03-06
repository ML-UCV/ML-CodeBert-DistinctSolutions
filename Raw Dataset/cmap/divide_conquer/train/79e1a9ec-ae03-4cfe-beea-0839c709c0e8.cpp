#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

ifstream f("cmap.in");
ofstream g("cmap.out");

class Point {
 public:
  double x, y;

  Point() {};

  static double distance(Point a, Point b) {
   double dx = a.x - b.x;
   double dy = a.y - b.y;
   return dx * dx + dy * dy;
  }
};

const int NMAX = 100000 + 1;

int n;
Point points[NMAX];
Point aux[NMAX];
Point middlePoints[NMAX];

bool comparator(Point a, Point b) {
 return a.x < b.x;
}

void readData() {
 f >> n;
 for (int i = 0; i < n; ++i) {
  f >> points[i].x;
  f >> points[i].y;
 }
}

int interclaseaza(double x, double d, int start, int end) {
 int mid = (start + end) / 2;
 int i = start;
 int j = mid + 1;
 int k = 0;
 int middlePointsCount = 0;

 while (i <= mid && j <= end) {
  if (points[i].y <= points[j].y) {
   if (x - points[i].x < d)
    middlePoints[middlePointsCount++] = points[i];
   aux[k++] = points[i++];
  }
  else {
   if (points[j].x - x < d)
    middlePoints[middlePointsCount++] = points[j];
   aux[k++] = points[j++];
  }
 }

 for (; i <= mid; ++i) {
  aux[k++] = points[i];
  if (x - points[i].x < d)
   middlePoints[middlePointsCount++] = points[i];
 }

 for (; j <= end; ++j) {
  aux[k++] = points[j];
  if (points[j].x - x < d)
   middlePoints[middlePointsCount++] = points[j];
 }


 for (int l = 0; l < k; ++l)
  points[start + l] = aux[l];

 return middlePointsCount;
}

double getClosestPair(int start, int end) {
 if (start + 1 == end) {
  if (points[end].y < points[start].y) {
   Point aux = points[end];
   points[end] = points[start];
   points[start] = aux;
  }
  return Point::distance(points[start], points[end]);
 }

 if (start >= end) return Point::distance(points[0], points[1]);

 int mid = (start + end) / 2;
 double middleX = points[mid].x;
 double sol = min(
   getClosestPair(start, mid),
   getClosestPair(mid + 1, end)
  );

 int k = interclaseaza(middleX, sol, start, end);

 for (int i = 0; i < k; ++i) {
  int lim = min(i + 8, k - 1);
  for (int j = i + 1; j <= lim; ++j)
   sol = min(sol, Point::distance(middlePoints[i], middlePoints[j]));
 }

 return sol;
}

int main() {
 readData();
 sort(points, points + n, comparator);
 g << fixed << std::setprecision(9) << sqrt(1.0 * getClosestPair(0, n - 1)) << '\n';
 return 0;
}
