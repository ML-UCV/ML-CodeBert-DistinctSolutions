#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstdio>
using namespace std;

pair<int, int> p[100005], c[100005];
int n;
long long inf;

long long solve(int l, int r);
bool cmp(pair<int, int> a, pair<int, int> b);
long long dist2(pair<int, int> a, pair<int, int> b);
void merge(int l, int m, int r);

int main() {
 freopen("cmap.in", "r", stdin);
 freopen("cmap.out", "w", stdout);
 cin >> n;
 for (int i = 0; i < n; ++i) {
  cin >> p[i].first >> p[i].second;
 }
 inf = dist2(p[0], p[1]);
 sort(p, p + n);
 printf("%.8lf", sqrt(solve(0, n - 1)));
}

long long solve(int l, int r) {
 int uy = 0;
 long long minim = inf;
 if (r - l < 3) {
  for (int i = l; i < r; ++i) {
   for (int j = i + 1; j <= r; ++j) {
    minim = min(minim, dist2(p[i], p[j]));
   }
  }
  sort(p + l, p + r + 1, cmp);

  return minim;
 }
 int m = (l + r) / 2;
 long long d1 = solve(l, m), d2 = solve(m + 1, r);
 if (d1 > d2) {
  d1 = d2;
 }
 minim = d1;
 merge(l, m, r);

 for (int i = l; i <= r; ++i) {
  if ((p[i].first - p[m].first) * (p[i].first - p[m].first) <= d1) {
   c[uy++] = p[i];
  }
 }
 for (int i = 0; i < uy; ++i) {
  for (int j = i + 1; j < uy && j <= i + 7; ++j) {
   minim = min(minim, dist2(c[i], c[j]));
  }
 }

 return minim;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
 if (a.second < b.second || (a.second == b.second && a.first < b.first)) {
  return 1;
 }
 return 0;
}

long long dist2(pair<int, int> a, pair<int, int> b) {
 return 1ll * (a.first - b.first) * (a.first - b.first) + 1ll * (a.second - b.second) * (a.second - b.second);
}

void merge(int l, int m, int r) {
 int k = -1, i, j;
 for (i = l, j = m + 1; i <= m && j <= r;) {
  if (cmp(p[i], p[j])) {
   c[++k] = p[i++];
  } else {
   c[++k] = p[j++];
  }
 }
 while (i <= m) {
  c[++k] = p[i++];
 }
 while (j <= r) {
  c[++k] = p[j++];
 }
 for (i = r; i >= l; --i) {
  p[i] = c[k--];
 }
}
