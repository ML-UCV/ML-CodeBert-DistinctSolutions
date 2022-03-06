#include <bits/stdc++.h>






using namespace std;



const int MAXN = 1e5;

const long long INF = 2000LL * 1000 * 1000 * 2000 * 1000 * 1000;

typedef pair < int, int > Point;



Point xsort[MAXN], ysort[MAXN], aux[MAXN];



inline long long dsqr(Point A, Point B) {

  return 1LL * (A.first - B.first) * (A.first - B.first) + 1LL * (A.second - B.second) * (A.second - B.second);

}



long long solve(int l, int r) {

  if (l >= r)

    return INF;

  if (l + 1 == r) {

    if (ysort[l] > ysort[r])

      swap(ysort[l], ysort[r]);

    return dsqr(ysort[l], ysort[r]);

  }

  int mid = (l + r) / 2, k = 0, i = l, j = mid + 1;

  long long lim = min(solve(l, mid), solve(mid + 1, r));

  while (i <= mid && j <= r)

    if (ysort[i] < ysort[j])

      aux[k++] = ysort[i++];

    else

      aux[k++] = ysort[j++];

  while (i <= mid)

    aux[k++] = ysort[i++];

  while (j <= r)

    aux[k++] = ysort[j++];

  for (int ind = l; ind <= r; ++ind)

    ysort[ind] = aux[ind - l];

  k = 0;

  for (int ind = l; ind <= r; ++ind)

    if (abs(ysort[ind].second - xsort[mid].first) <= lim)

      aux[k++] = ysort[ind];

  for (i = 0; i < k; ++i)

    for (j = i + 1; j < min(k, i + 8); ++j)

      lim = min(lim, dsqr(aux[i], aux[j]));

  return lim;

}



int main()

{

    int n;

    ifstream fin("cmap.in");

    fin >> n;

    for (int i = 0; i < n; ++i)

      fin >> xsort[i].first >> xsort[i].second;

    fin.close();

    sort(xsort, xsort + n);

    for (int i = 0; i < n; ++i)

      ysort[i] = {xsort[i].second, xsort[i].first};

    ofstream fout("cmap.out");

    fout << setprecision(8) << fixed << sqrt(solve(0, n - 1)) << '\n';

    fout.close();

    return 0;

}
