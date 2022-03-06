#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
struct punct
{
 int x,y;
}v[100010],v1[100010];

int cmp1(punct a,punct b)
{
 return a.x<b.x;
}

int cmp2(punct a,punct b)
{
 return a.y<b.y;
}

long long sqr(int x)
{
 return 1LL*x*x;
}

long long dist(punct a,punct b)
{
 return sqr(a.x-b.x)+sqr(a.y-b.y);
}

long long solve(int st,int dr)
{
 if(st>=dr) return inf;
 if(st+1==dr)
 {
  if(cmp2(v[dr],v[st])) swap(v[st],v[dr]);
  return dist(v[st],v[dr]);
 }
 int mid=(st+dr)/2,midx=v[mid].x;
 long long sol=min(solve(st,mid),solve(mid+1,dr));
 merge(v+st,v+mid+1,v+mid+1,v+dr+1,v1+st,cmp2);
 int nr=0;
 for(int i=st;i<=dr;i++)
 {
  v[i]=v1[i];
  if(sqr(v1[i].x-midx)<=sol) v1[++nr]=v1[i];
 }
 for(int i=1;i<=nr;i++)
  for(int j=i+1;j<=nr && sqr(v1[i].y-v1[j].y)<=sol;j++)
   sol=min(sol,dist(v1[i],v1[j]));
 return sol;
}

int main()
{
 freopen("cmap.in", "r" ,stdin);
 freopen("cmap.out", "w", stdout);
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++) scanf("%d%d",&v[i].x,&v[i].y);
 sort(v+1,v+1+n,cmp1);
 printf("%.9f",sqrt(solve(1,n)));
 return 0;
}
