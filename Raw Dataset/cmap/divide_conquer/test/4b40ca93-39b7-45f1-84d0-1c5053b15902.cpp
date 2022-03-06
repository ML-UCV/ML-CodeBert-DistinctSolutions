#include <cstdio>
#include <vector>#include <math.h>
#include <cstdio>
#include <algorithm>
using namespace std;



FILE *in = fopen("cmap.in", "r");

FILE *out = fopen("cmap.out", "w");



const int maxN = 1e5 + 5;

const long long inf = 1e18;

const int maxDiff = 8;



int n;

 pair<int, int > pts[maxN], aux[maxN];



void citire() {

  fscanf(in,"%d", &n);

  for(int i = 0; i < n; i++) {

    fscanf(in,"%d%d", &pts[i].first, &pts[i].second);

  }

}



void Merge(int left, int mid, int right) {

  int p1 = left, p2 = mid + 1, pos = 0;



  while(p1 <= mid && p2 <= right)

  {

    if(pts[p1].second < pts[p2].second)

    {

      aux[pos] = pts[p1]; p1++; pos++;

    } else

    {

      aux[pos] = pts[p2]; p2++; pos++;

    }

  }



  while(p1 <= mid)

    {

    aux[pos] = pts[p1]; p1++; pos++;

    }



  while(p2 <= right)

  {

    aux[pos] = pts[p2]; p2++; pos++;

  }



  for(int i = 0; i < pos; i++) {

    pts[left + i] = aux[i];

  }

}



long long dist( pair<int, int > A, pair<int, int > B) {

  return 1LL * (A.first - B.first) * (A.first - B.first) + 1LL * (A.second - B.second) * (A.second - B.second);

}



long long divide(int left, int right) {

  if(right - left < 2)

    {

    if(right == left)

      return inf;

  else {

      Merge(left, left, right);

      return dist(pts[left], pts[right]);

    }

  }



  int mid = (left + right) / 2;

  long long d1 = divide(left, mid), d2 = divide(mid + 1, right);



  long long d = min(d1, d2);

  Merge(left, mid, right);



  for(int i = left; i <= right; i++)

    for(int j = i - 1; j >= left && i - j < maxDiff; j--)

      d = min(d, dist(pts[i], pts[j]));



  return d;

}



int main() {

  citire();



  sort(pts, pts + n);



  fprintf(out,"%.7f\n", sqrt((double)divide(0, n - 1)));



  return 0;

}
