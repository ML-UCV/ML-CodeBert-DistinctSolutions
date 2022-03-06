#include <cmath>
#include <cstring>
#include <fstream>
#include <queue>
#include <vector>




using namespace std;

ifstream fi ("dmin.in");
ofstream fo ("dmin.out");
double dst[1501];
int n, m, a, b, c, val[1501];
struct str
{
 int n;
 double c;
 bool operator < (const str &other) const
 {
  return c - other.c > 0.0000001;
 }
} x;
priority_queue <str> pq;
vector <str> v[1501];

void dijkstra()
{
 pq.push({1, 0});
 dst[1] = 0;
 while (!pq.empty())
 {
  x = pq.top();
  pq.pop();
  if (dst[x.n] < x.c - 0.0000001)
   continue;
  for (auto i:v[x.n])
  {
   if ( - i.c - x.c + dst[i.n] > 0.0000001)
   {
    dst[i.n] = i.c + x.c;
    pq.push({i.n, dst[i.n]});
   }
  }
 }
}

void recalibrate()
{
 val[1] = 1;
 for (int i = 2; i <= n; ++i)
   for (auto j:v[i])
    if (abs(dst[i] - dst[j.n] - j.c) <= 0.0000001)
     val[i] = (val[j.n] + val[i])%104659;
}

int main()
{
 fi >> n >> m;
 for (int i = 1; i <= n; ++i)
  dst[i] = 0x3f3f3f3f;
 for (int i = 1; i <= m; ++i)
 {
  fi >> a >> b >> c;
  v[a].push_back({b, log10(c)});
  v[b].push_back({a, log10(c)});
 }
 dijkstra();
 recalibrate();
 for (int i = 2; i <= n; ++i)
  fo << val[i]%104659 << ' ';
 return 0;
}
