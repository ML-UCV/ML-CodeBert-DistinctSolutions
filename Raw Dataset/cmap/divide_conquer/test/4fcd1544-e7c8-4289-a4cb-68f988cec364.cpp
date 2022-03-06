#include <bits/stdc++.h>
using namespace std;



typedef int64_t i64;

typedef pair<int, int> Point;



const int NMAX = 100010;

const i64 inf = 4e18;



int N;

Point X[NMAX], Y[NMAX], aux[NMAX];



inline i64 squareDist(const Point &A, const Point &B) {

 return 1ll * (A.first - B.first) * (A.first - B.first) + 1ll * (A.second - B.second) * (A.second - B.second);

}



struct CompareY {

 bool operator()(const Point &lhs, const Point &rhs) const {

  return lhs.second < rhs.second ? 1 : (lhs.second == rhs.second ? lhs.first < rhs.first : 0);

 }

};



i64 computeMinDist(int left, int right) {

 if (left == right)

  return inf;

 if (right - left == 1) {

  if (Y[left].second > Y[right].second)

   swap(Y[left], Y[right]);

  return squareDist(X[left], X[right]);

 }



 int mid = (left + right) / 2;

 i64 minSqrDist = min(computeMinDist(left, mid), computeMinDist(mid + 1, right));



 merge(Y + left, Y + mid + 1, Y + mid + 1, Y + right + 1, aux, CompareY());

 memcpy(Y + left, aux, (right - left + 1) * sizeof(Point));



 int pos = 0;

 for (int i = left; i <= right; ++i)

  if (1ll * (X[mid].first - Y[i].first) * (X[mid].first - Y[i].first) <= minSqrDist)

   aux[pos++] = Y[i];



 for (int i = 0; i < pos; ++i)

  for (int j = i + 1; j < i + 8 && j < pos; ++j)

   minSqrDist = min(minSqrDist, squareDist(aux[i], aux[j]));



 return minSqrDist;

}



int main() {

 assert(freopen("cmap.in", "r", stdin));

 assert(freopen("cmap.out", "w", stdout));



 int i;



 cin >> N;

 for (i = 1; i <= N; ++i)

  cin >> X[i].first >> X[i].second;

 sort(X + 1, X + N + 1);

 memcpy(Y, X, sizeof Y);



 cout << fixed << setprecision(6) << sqrt(computeMinDist(1, N)) << '\n';



 return 0;

}
