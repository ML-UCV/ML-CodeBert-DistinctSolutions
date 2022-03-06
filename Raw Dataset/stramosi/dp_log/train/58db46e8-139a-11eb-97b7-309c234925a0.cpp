#include <bits/stdc++.h>




using namespace std;
typedef long long ll;
ifstream fin("stramosi.in");
ofstream fout("stramosi.out");
int n, m, i, j, v[250005][20], x, p, q, p2, ip;
int main()
{
 fin>>n>>m;
 for(i=1;i<=n;++i)
  {
   fin>>x;
   v[i][0]=x;
   j=0;
   do
   {
    ++j;
    v[i][j]=v[v[i][j-1]][j-1];
   }while(v[i][j]);
  }
 for(i=1;i<=m;++i)
 {
  fin>>q>>p;
  p2=1;
  ip=0;
  while(p2<=p)
  {
   p2*=2;
   ++ip;
  }
  p2/=2;
  --ip;
  while(p&&q)
  {
   while(p2>p)
   {
    p2/=2;
    --ip;
   }
   p-=p2;
   q=v[q][ip];
  }
  fout<<q<<'\n';
 }
}
