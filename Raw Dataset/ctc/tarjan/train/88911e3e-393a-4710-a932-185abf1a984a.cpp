#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;

int n, m;
VVI G, ctc;
VI niv, L, c;
VB inStk;
stack<int> stk;

void Read();
void Tarjan(int x, int& level);
void Write();

int main()
{
 Read();
 int level{1};
 for (int i = 1; i <= n; i++)
  if (!niv[i])
   Tarjan(i, level);
 Write();
}

void Tarjan(int x, int& level)
{
 niv[x] = L[x] = level;
 level++;
 stk.push(x);
 inStk[x] = true;

 for (const int& y : G[x])
 {
  if (!niv[y])
  {
   Tarjan(y, level);
   L[x] = min(L[x], L[y]);
  }
  else
   if (inStk[y])
    L[x] = min(L[x], niv[y]);
 }

 if (L[x] == niv[x])
 {
  c = VI();
  while (!stk.empty())
  {
   int y = stk.top();
   stk.pop();
   inStk[y] = false;
   c.emplace_back(y);
   if (y == x)
    break;
  }
  ctc.emplace_back(c);
 }
}

void Write()
{
 ofstream fout("ctc.out");
 fout << ctc.size() << '\n';
 for (const VI& c : ctc)
 {
  for (const int& x : c)
   fout << x << ' ';
  fout << '\n';
 }
}

void Read()
{
 ifstream fin("ctc.in");
 fin >> n >> m;
 G = VVI(n + 1);
 niv = L = VI(n + 1);
 inStk = VB(n + 1);

 int x, y;
 for (int i = 0; i < m; i++)
 {
  fin >> x >> y;
  G[x].emplace_back(y);
 }
}
