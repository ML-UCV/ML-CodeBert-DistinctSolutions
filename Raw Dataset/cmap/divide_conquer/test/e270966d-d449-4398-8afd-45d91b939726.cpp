#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>




struct Point2D {

 double X, Y;

};



bool myComp(const Point2D& PointA, const Point2D& PointB) {

 if (PointA.X < PointB.X)

  return true;

 if (PointA.X == PointB.X)

  if (PointA.Y <= PointB.Y)

   return true;

 return false;

}



bool myCompY(const Point2D& PointA, const Point2D& PointB) {

 if (PointA.Y < PointB.Y)

  return true;

 return false;

}



double distance(const Point2D& PointA, const Point2D& PointB) {

 return std::pow(PointB.X - PointA.X, 2) + std::pow(PointB.Y - PointA.Y, 2);

}



double divide(std::vector<Point2D>::iterator itBegin, std::vector<Point2D>::iterator itEnd) {

 if (itEnd - itBegin <= 3) {

  double result = DBL_MAX;

  for (auto it1 = itBegin; it1 < itEnd; ++it1) {

   for (auto it2 = it1 + 1; it2 < itEnd; ++it2) {

    if (it1->Y > it2->Y)

     std::iter_swap(it1, it2);

    result = std::min(result, distance(*it1, *it2));

   }

  }

  return result;

 }

 auto itMiddle = itBegin + (itEnd - itBegin) / 2;

 double result = std::min(divide(itBegin, itMiddle), divide(itMiddle, itEnd));

 std::vector<Point2D> aux(itEnd - itBegin);

 std::merge(itBegin, itMiddle, itMiddle, itEnd, aux.begin(), myCompY);

 std::copy(aux.begin(), aux.end(), itBegin);

 aux.clear();

 for (auto it = itBegin; it < itEnd; ++it)

  if (std::abs(it->X - itMiddle->X) <= result)

   aux.push_back(*it);

 for (auto it1 = aux.begin(); it1 < aux.end(); ++it1)

  for (auto it2 = it1 + 1; it2 < aux.end() && it2 - it1 < 8; ++it2)

   result = std::min(result, distance(*it1, *it2));

 aux.clear();

 return result;

}



int main() {

 std::ifstream f("cmap.in");

 std::vector<Point2D> Points;

 int n;

 f >> n;

 for (int i = 0; i < n; ++i) {

  Point2D newPoint;

  f >> newPoint.X >> newPoint.Y;

  Points.push_back(newPoint);

 }

 f.close();

 std::sort(Points.begin(), Points.end(), myComp);

 double result = divide(Points.begin(), Points.end());

 std::ofstream g("cmap.out");

 g << std::fixed << std::setprecision(6) << std::sqrt(result);

 g.close();

 Points.clear();

 return 0;

}
