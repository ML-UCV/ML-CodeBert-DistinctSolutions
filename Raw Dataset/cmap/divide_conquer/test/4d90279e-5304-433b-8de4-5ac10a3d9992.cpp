#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>







typedef long long int64;
typedef std::pair<int64, int64> Point;


int64 distance(const Point& a, const Point &b)
{
 return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int64 cmap(const std::vector<Point> &points, std::vector<Point> &pointsY, int left, int right)
{
 if (right - left == 2) {
  if (pointsY[left] > pointsY[left+1]) {
   std::swap(pointsY[left], pointsY[left+1]);
  }
  return distance(points[left], points[left+1]);
 }
 if (right - left <= 1) {
  return (4e18L);
 }

 int mid = (left + right) / 2;

 int64 minLeft = cmap(points, pointsY, left, mid);
 int64 minRight = cmap(points, pointsY, mid, right);

 int64 minDist = minLeft;
 if (minRight < minDist) minDist = minRight;

 std::vector<Point> cand(right - left);
 std::merge(pointsY.begin() + left, pointsY.begin() + mid, pointsY.begin() + mid, pointsY.begin() + right, cand.begin());
 std::copy(cand.begin(), cand.begin() + (right - left), pointsY.begin() + left);

 int el = 0;
 for (int i = left; i < right; ++ i) {
  if (abs(pointsY[i].second - points[mid].first) <= minDist) {
   cand[el++] = pointsY[i];
  }
 }

 for (int i = 0; i < el; ++ i) {
  for (int j = i+1; j < el && j - i < 8; ++ j) {
   int64 dist = distance(cand[i], cand[j]);
   if (minDist > dist) {
    minDist = dist;
   }
  }
 }

 return minDist;
}

int main (int argc, char const *argv[])
{
 std::ifstream in("cmap.in");

 int N;
 in >> N;

 std::vector<Point> points(N);
 std::vector<Point> pointsY(N);
 for (int i = 0; i < N; ++ i) {
  int64 first, second;
  in >> first >> second;
  points[i].first = first;
  points[i].second = second;
 }

 in.close();

 std::sort(points.begin(), points.end(), [](const Point& a, const Point &b) {
  if (a.first == b.first)
   return a.second < b.second;
  return a.first < b.first;
 });
 int cnt = 0;
 for (auto &a : points) {
  pointsY[cnt].second = a.first;
  pointsY[cnt++].first = a.second;
 }

 std::ofstream out("cmap.out");

 out << std::fixed << std::setprecision(6) << sqrt(cmap(points, pointsY, 0, N)) << "\n";

 out.close();

 return 0;
}
