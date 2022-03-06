#include <bits/stdc++.h>

using namespace std;
struct muchii {
 int x,y,cost;
 bool operator < (const muchii &a) const {
  return cost<a.cost;
 }
}v[400003];
int n,m,tata[200003],suma,kontor,nod,nod1;pair <int,int> sol[200003];
int find_root (int x) {
 if(x==tata[x])
  return x;
 else {
  tata[x]=find_root(tata[x]);
  return tata[x];
 }
}
void apeme () {
 for(int i=1;i<=n;++i)
  tata[i]=i;
 for(int i=1;i<=m;++i) {
  nod=find_root(v[i].x);nod1=find_root(v[i].y);
  if(nod!=nod1)
   suma+=v[i].cost,sol[++kontor]={v[i].x,v[i].y},tata[nod]=nod1;
 }
}
int main () {
 freopen("apm.in","r",stdin);
 freopen("apm.out","w",stdout);
 scanf("%d%d", &n, &m);
 for(int i=1;i<=m;++i)
  scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].cost);
 sort(v+1,v+m+1);apeme();
 printf("%d\n%d\n", suma, kontor);
 for(int i=1;i<=kontor;++i)
  printf("%d %d\n", sol[i].first, sol[i].second);
 return 0;
}
