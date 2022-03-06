#include <cstdio>
#include <cstdlib>#include <math.h>
#include <cassert>
#include <vector>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long LL;
const int MAXN = 100010;

pair<int, int> v[MAXN];

int auxv[MAXN], avsz;

int N;



LL dst(int i, int j) {

  int dx = v[i].first - v[j].first;

  int dy = v[i].second - v[j].second;

  return 1LL * dx * dx + 1LL * dy * dy;

}



LL brute(int left, int right) {

  LL res = LLONG_MAX;

  for (int i = left; i < right; ++i)

  for (int j = i + 1; j < right; ++j)

    res = min(res, dst(i, j));

  return res;

}



bool smallerY(pair<int, int> p1, pair<int, int> p2) {

  if (p1.second != p2.second) return p1.second < p2.second;

  return p1.first < p2.first;

}



LL cmap(int left, int right) {

  int L = right - left;

  if (L <= 3) {

    sort(v + left, v + right, smallerY);

    return brute(left, right);

  }

  int mid = left + L / 2;

  int xmid = v[mid].first;

  LL delta = min(cmap(left, mid), cmap(mid, right));

  inplace_merge(v + left, v + mid, v + right, smallerY);

  avsz = 0;

  for (int i = left; i < right; ++i) {

    int dx = v[i].first - xmid;

    if (1LL * dx * dx > delta) continue;

    auxv[avsz++] = i;

  }

  LL best = delta;

  for (int ii = 0; ii < avsz; ++ii) {

    int lim = min(avsz, ii + 8);

    for (int j = ii + 1; j < lim; ++j)

      best = min(best, dst(auxv[ii], auxv[j]));

  }

  return best;

}



int main() {

  assert(freopen("fis.in", "r", stdin));

  assert(freopen("fis.out", "w", stdout));

  scanf("%d", &N);

  for (int i = 0; i < N; ++i)

    scanf("%d%d", &v[i].first, &v[i].second);

  sort(v, v + N);

  printf("%.8lf\n", sqrt(cmap(0, N)));

  return 0;

}
