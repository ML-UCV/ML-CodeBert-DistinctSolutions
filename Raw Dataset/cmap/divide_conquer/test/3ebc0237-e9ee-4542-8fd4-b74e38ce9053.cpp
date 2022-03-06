#include <bits/stdc++.h>


using namespace std;

ifstream f("cmap.in");
ofstream g("cmap.out");
int n;
vector<pair<long long, long long>> x, y, v;

long long dist(pair<long long, long long> p1, pair<long long, long long> p2)
{
  return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

long long solve(int st, int dr)
{
    if(st >= dr)
      return 0x3f3f3f3f;
    if(dr - st == 1)
        return dist(x[st], x[st + 1]);
    int mid = (st + dr) / 2;
    long long best = min(solve(st, mid), solve(mid, dr));

    sort(y.begin() + st, y.begin() + dr);

    v.clear();
    for(int i = st;i < dr;++i)
      if(abs(y[i].second - x[mid].first) <= best)
        v.push_back(y[i]);
    for(int i = 0;i < v.size() - 1;++i)
      for(int j = i + 1;j < v.size() && j - i < 8;++j)
        best = min(best, dist(v[i], v[j]));
    return best;
}

void Read()
{
  f>>n;
  long long a, b;
  for(int i = 1;i <= n;++i)
  {
    f>>a>>b;
    x.push_back(make_pair(a, b));
  }
  sort(x.begin(), x.end());
  for(auto it : x)
    y.push_back(make_pair(it.second, it.first));
  g<<setprecision(6)<<fixed<<sqrt(solve(0, n));
}

int main()
{
  Read();
  return 0;
}
