#include <bits/stdc++.h>
using namespace std;



ifstream in("cmap.in");

ofstream out("cmap.out");



int n, vf;

pair <long long, long long> a[100100], L, wek[100100];



long long dist(const pair <long long, long long> &a, const pair <long long, long long> &b) {

 return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);

}



bool cmp(const pair <long long, long long> &a, const pair <long long, long long> &b) {

 if (a.second == b.second)

  return a.first < b.first;

 return a.second < b.second;

}



long long solve(int st, int dr) {

 if (dr - st + 1 <= 3) {

  long long bst = LLONG_MAX;

  for (int i = st; i < dr; i++)

   for (int j = i + 1; j <= dr; j++)

    bst = min(bst, dist(a[i], a[j]));

  return bst;

 }

 int mid = st + dr >> 1;

 long long bst = min(solve(st, mid), solve(mid + 1, dr));

 long long v = a[mid].first;

 vf = 0;

 for (int i = st; i <= mid; i++)

  if (abs(a[i].first - v) <= bst)

   wek[++vf] = a[i];

 sort(wek + 1, wek + vf + 1, cmp);

 for (int i = 1; i <= vf; i++)

  for (int j = i + 1; j <= vf && j - i <= 7; j++)

   bst = min(bst, dist(wek[i], wek[j]));

 return bst;

}



int main() {

 ios_base::sync_with_stdio(0);

 cin.tie(NULL);

 in >> n;

 for (int i = 1; i <= n; i++)

  in >> a[i].first >> a[i].second;

 sort(a + 1, a + n + 1);

 out << fixed << setprecision(6) << sqrt((long double) solve(1, n));

 return 0;

}
