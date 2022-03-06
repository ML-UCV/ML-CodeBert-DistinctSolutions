#include <bits/stdc++.h>

using namespace std;

int aib[30010], v[30010];
int n;

void update(int poz, int val)
{
 for (int i = poz; i <= n; i += (i & -i))
  aib[i] += val;
}

int sum(int poz)
{
 int s = 0, i;
 for (i = poz; i >= 1; i -= (i & -i))
  s += aib[i];

 return s;
}

int caut(int st, int dr, int p)
{
 int val, mij, poz;
 while(st <= dr)
 {
  mij = (st + dr) / 2;
  val = sum(mij);
  if(val >= v[p])
  {
   poz = mij;
   dr = mij - 1;
  }
  else
  {
   st = mij + 1;
  }
 }
 return poz;
}
int final[30010];
int main()
{
 ifstream f("schi.in");
 ofstream g("schi.out");
 f>>n;

 int i, p;

 for (i = 1; i <= n; i++)
 {
  f>>v[i];
  update(i, 1);
 }

 for (i = n; i >=1; i--)
 {
  p = caut(1, n, i);
  final[p] = i;
  update(p, -1);
 }

 for(i = 1; i<= n; i++)
 {
  g<<final[i]<<"\n";
 }
 return 0;
}
