#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

const int N = 1e5 + 5;

vector<int> g[N], gt[N], ordine, componenteConexe[N];
bool vizitat[N], cc[N];

void dfs1(int nod)
{
 vizitat[nod] = true;

 for (int next : g[nod])
  if (!vizitat[next])
   dfs1(next);

 ordine.push_back(nod);
}

void dfs2(int nod, int ccx)
{
 cc[nod] = true;
 componenteConexe[ccx].push_back(nod);

 for (int next : gt[nod])
  if (!cc[next])
   dfs2(next, ccx);
}

int main()
{
 int n, m;
 fin >> n >> m;

 for (int i = 0; i < m; i++)
 {
  int x, y;
  fin >> x >> y;
  g[x].push_back(y);
  gt[y].push_back(x);
 }

 for (int i = 1; i <= n; i++)
 {
  if (!vizitat[i])
   dfs1(i);
 }

 int cci = 1;
 for (int i = ordine.size() - 1; i >= 0; i--)
 {
  if (!cc[ordine[i]])
   dfs2(ordine[i], cci++);
 }

 fout << cci - 1 << '\n';
 for (int i = 1; i < cci; i++)
 {
  for (int nod : componenteConexe[i])
   fout << nod << ' ';
  fout << '\n';
 }
}
