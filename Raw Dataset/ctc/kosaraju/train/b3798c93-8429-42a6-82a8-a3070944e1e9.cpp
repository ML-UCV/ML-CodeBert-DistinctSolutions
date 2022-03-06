#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>






using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;

VVI G, GT;
VB v;
stack<int> stk;

VI c;
VVI ctc;

int n, m;

void CitesteGraf();
void Kosaraju();
void Df(int x);
void DfT(int x);
void AfiseazaCompTareConexe();


int main()
{
 CitesteGraf();
 Kosaraju();
 AfiseazaCompTareConexe();
}

void CitesteGraf()
{
 fin >> n >> m;
 G = GT = VVI(n + 1);
 v = VB(n + 1);
 int x, y;
 for (int i = 1; i <= m; ++i)
 {
  fin >> x >> y;
  G[x].emplace_back(y);
  GT[y].emplace_back(x);
 }
}

void Kosaraju()
{
 for (int x = 1; x <= n; ++x)
  if (!v[x])
   Df(x);

 v.assign(n + 1, false);

 int x;
 while (!stk.empty())
 {
  x = stk.top(); stk.pop();
  if (v[x]) continue;
  c.clear();
  DfT(x);
  ctc.emplace_back(c);
 }
}

void Df(int x)
{
 v[x] = true;
 for (const int y : G[x])
 {
  if (v[y]) continue;
  Df(y);
 }
 stk.push(x);
}

void DfT(int x)
{
 v[x] = true;
 c.emplace_back(x);

 for (const int& y : GT[x])
 {
  if (v[y]) continue;
  DfT(y);
 }
}

void AfiseazaCompTareConexe()
{
 fout << ctc.size() << '\n';

 for (const auto& comp : ctc)
 {
  for (const int& x : comp)
   fout << x << ' ';
  fout << '\n';
 }
}
