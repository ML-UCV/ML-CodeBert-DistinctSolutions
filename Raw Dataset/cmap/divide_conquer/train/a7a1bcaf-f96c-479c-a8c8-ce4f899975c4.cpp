#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmap.in");
ofstream fout("cmap.out");



const long long INF = 4e18;

vector <pair <long long, long long> > points;

long long sq(long long x)
{
 return x * x;
}

long long dist(pair <long long, long long> A, pair <long long, long long> B)
{
 return (sq(A.first - B.first) + sq(A.second - B.second));
}

long long solve(long long l, long long r)
{
 if(r - l <= 3)
 {
  long long res = INF;

  for(long long i = l; i < r; i++)
   for(long long j = i + 1; j <= r; j++)
    res = min(res, dist(points[i], points[j]));

  return res;
 }

 long long mid = (l + r) / 2;
 long long d = min(solve(l, mid), solve(mid + 1, r));

 vector <pair <long long, long long> > aux;

 for(long long i = l; i <= r; i++)
  if(abs(points[mid].first - points[i].first) <= d)
   aux.push_back({points[i].second, points[i].first});

 sort(aux.begin(), aux.end());

 for(long long i = 0; i < aux.size(); i++)
  for(long long j = i + 1; j < aux.size() && j - i < 8; j++)
   d = min(d, dist(aux[i], aux[j]));

 return d;
}

main()
{
  long long n;
  fin >> n;

  for(long long i = 1; i <= n; i++)
  {
   long long x, y;
   fin >> x >> y;

   points.push_back({x, y});
  }

  sort(points.begin(), points.end());

  fout << fixed << setprecision(6) << sqrt(1.0 * solve(0, n - 1)) << '\n';
}
