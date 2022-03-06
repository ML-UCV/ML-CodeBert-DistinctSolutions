#include <bits/stdc++.h>

using namespace std;

ifstream in("stramosi.in");
ofstream out("stramosi.out");

const int DIM = 3e5 + 7;

int ancestor[30][DIM];

int main()
{
 int n, m;
 in >> n >> m;

 for(int i = 1; i <= n; i++)
 {
  in >> ancestor[0][i];
 }

 for(int i = 1; (1 << i) <= n; i++)
  for(int j = 1; j <= n; j++)
   ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];

 while(m--)
 {
  int p, q;
  in >> q >> p;

  while(p != 0 && q != 0)
  {
   int k = p & (-p);

   p -= k;

   int t = log2(k);
   if(1 << t != k)
    t++;

   q = ancestor[t][q];
  }

  out << q << '\n';
 }
}
