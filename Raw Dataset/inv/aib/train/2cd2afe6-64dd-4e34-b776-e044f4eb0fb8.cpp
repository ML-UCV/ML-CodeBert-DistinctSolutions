#include <bits/stdc++.h>

using namespace std;
ifstream f("inv.in");
ofstream g("inv.out");
pair<int, int> v[100005];
int n;
int aib[100005];

void Read()
{
  f>>n;
  for(int i = 1;i <= n;++i)
    {
      f>>v[i].first;
      v[i].second = i;
    }
  sort(v + 1, v + n + 1);
}

int query(int x)
{
  int sum = 0;
  for(int i = x;i;i -= (( i ^ (i - 1)) & i))
    sum += aib[i];
  return sum;
}

void update(int x)
{
  for(int i = x;i <= n;i += (( i ^ (i - 1)) & i))
    aib[i]++;
}

void Solve()
{
  int res = 0;
  for(int i = 1;i <= n;++i)
    {
      update(v[i].second);
      res = (res + query(n) - query(v[i].second)) % 9917;
    }
  g<<res;
}

int main()
{
  Read();
  Solve();
  return 0;
}
