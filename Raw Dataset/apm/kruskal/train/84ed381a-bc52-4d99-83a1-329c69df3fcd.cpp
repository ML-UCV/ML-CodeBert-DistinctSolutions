#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
 int x, y, w;

 bool operator < (const Edge& e) const
 {
  return w < e.w;
 }
};

using VI = vector<int>;
using VE = vector<Edge>;

int n, m, cost;
VE G, apm;
VI t, h;

void Read();
void Kruskal();
int Find(int x);
void Union(int x, int y);
void Write();

int main()
{
 Read();
 Kruskal();
 Write();
}

void Kruskal()
{
 t = h = VI(n + 1);
 for (int i = 1; i <= n; i++)
  t[i] = i;

 sort(G.begin(), G.end());
 int c1, c2, cnt{0};
 for (Edge e : G)
 {
  c1 = Find(e.x);
  c2 = Find(e.y);
  if (c1 == c2)
   continue;
  Union(c1, c2);
  apm.emplace_back(e);
  cost += e.w;
  cnt++;
  if (cnt == n - 1)
   break;
 }
}

int Find(int x)
{
 if (t[x] == x) return x;
 return t[x] = Find(t[x]);
}

void Union(int x, int y)
{
 if (h[x] > h[y])
  t[y] = x;
 else
 {
  t[x] = y;
  if (h[x] == h[y])
   h[y]++;
 }
}

void Write()
{
 ofstream fout("apm.out");
 fout << cost << '\n' << n - 1 << '\n';
 for (const Edge& e : apm)
  fout << e.x << ' ' << e.y << '\n';
}

void Read()
{
 ifstream fin("apm.in");
 fin >> n >> m;

 int x, y, w;
 for (int i = 0; i < m; i++)
 {
  fin >> x >> y >> w;
  G.push_back({x, y, w});
 }
}
