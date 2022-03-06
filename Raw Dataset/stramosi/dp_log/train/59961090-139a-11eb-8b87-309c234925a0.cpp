#include <bits/stdc++.h>

using namespace std;
int n,m,tata[250005],str[35][250005],l[250005];
void build_str () {
 for(int i=2;i<=n;++i)
  l[i]=l[(i>>1)]+1;
 for(int i=1;i<=n;++i)
  str[0][i]=tata[i];
 for(int k=1;(1<<k)<=n;++k)
  for(int i=1;i<=n;++i)
   str[k][i]=str[k-1][str[k-1][i]];
}
int querrys (int x, int p) {
 for(int i=0;p>0;++i)
  if((p & (1<<i))!=0)
   p^=(1<<i),x=str[i][x];
 return x;
}
int main () {
 int nr1,nr2;
 freopen("stramosi.in","r",stdin);
 freopen("stramosi.out","w",stdout);
 scanf("%d%d", &n, &m);++m;
 for(int i=1;i<=n;++i)
  scanf("%d", &tata[i]);
 build_str();
 while(--m) {
  scanf("%d%d", &nr1, &nr2);
  printf("%d\n", querrys(nr1,nr2));
 }
 return 0;
}
