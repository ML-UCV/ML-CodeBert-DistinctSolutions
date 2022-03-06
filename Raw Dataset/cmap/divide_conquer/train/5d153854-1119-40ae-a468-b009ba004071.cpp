#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

template <typename T>
class Point
{
 public:
  Point() = default;
  Point(T x, T y): x_(x), y_(y) {}
  T x() const {return x_;}
  T y() const {return y_;}
  bool operator < (const Point& other) const {
    if (x() == other.x())
      return y() < other.y();
    return x() < other.x();
  }
  bool operator > (const Point& other) const {
    return !(*this < other);
  }
 private:
  T x_, y_;
};

int N;
vector<Point<double>> X, Y, aux;

template <typename T>
T dist(Point<T> p1, Point<T> p2) {
  return (p1.x() - p2.x())*(p1.x() - p2.x()) +
         (p1.y() - p2.y())*(p1.y() - p2.y());
}

template <typename T>
T cmap(int left, int right)
{
  if (right - left == 1)
    return numeric_limits<T>::max();

  if (right - left == 2) {
    if (Y[left] > Y[left + 1])
      swap(Y[left], Y[left+1]);
    return dist(X[left], X[left+1]);
  }

  int mid = (left + right) / 2;
  T delta = min(cmap<T>(left, mid), cmap<T>(mid, right));


  merge(Y.begin() + left, Y.begin() + mid, Y.begin() + mid, Y.begin() + right, aux.begin());
  copy(aux.begin(), aux.begin() + (right - left), Y.begin() + left);


  int sizeAux = 0;
  for (int i = left; i < right; ++i)
    if (abs(X[mid].x() - Y[i].y()) <= delta + 0.0000001)
      aux[sizeAux++] = Y[i];

  for (int i = 0; i < sizeAux; ++i)
    for (int j = i + 1; j < sizeAux && j - i <= 7; ++j)
      delta = min(delta, dist<T>(aux[i], aux[j]));
  return delta;
}

int main()
{
  ifstream fin("cmap.in");
  ofstream fout("cmap.out");

  ios::sync_with_stdio(false);
  fin.tie(0);

  fin >> N;
  aux.resize(N);
  double x,y;
  for (int i = 0 ; i < N; ++i) {
    fin >> x >> y;
    X.emplace_back(x, y);
  }
  sort(X.begin(), X.end());
  for (int i = 0; i < N; ++i)
    Y.emplace_back(X[i].y(), X[i].x());

  fout << fixed << setprecision(6) << sqrt(cmap<double>(0, N)) << "\n";

  return 0;
}
