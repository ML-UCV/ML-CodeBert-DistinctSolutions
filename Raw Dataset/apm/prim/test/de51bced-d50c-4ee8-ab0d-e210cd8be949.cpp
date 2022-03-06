#include <bits/stdc++.h>

using namespace std;
struct muchii {
 int x,y,cost;
 bool operator < (const muchii &a) const {
  return cost>a.cost;
 }
}var,var1;
int n,m,viz[200003],kontor,suma;vector <pair <int,int> > graf[200003];priority_queue <muchii> chestie;pair <int,int> sol[200003];
void prim () {
 while(!chestie.empty()) {
  var=chestie.top();
  if(viz[var.x]==1) {
   chestie.pop();
   continue;
  }
  viz[var.x]=1;chestie.pop();
  if(var.x!=var.y) {
   sol[++kontor]={var.x,var.y};
   suma+=var.cost;
  }
  for(int i=0;i<(int)graf[var.x].size();++i)
   if(viz[graf[var.x][i].first]==0) {
    var1.x=graf[var.x][i].first,var1.y=var.x,var1.cost=graf[var.x][i].second,chestie.push(var1);
   }
 }
}
int main () {
 int nr,nr1,nr2;
 freopen("apm.in","r",stdin);
 freopen("apm.out","w",stdout);
 scanf("%d%d", &n, &m);
 for(int i=1;i<=m;++i) {
  scanf("%d%d%d", &nr, &nr1, &nr2);
  graf[nr].push_back({nr1,nr2});graf[nr1].push_back({nr,nr2});
 }
 var.x=1;var.y=1;var.cost=0;
 chestie.push(var);prim();
 printf("%d\n%d\n", suma, kontor);
 for(int i=1;i<=kontor;++i)
  printf("%d %d\n", sol[i].first, sol[i].second);
 return 0;
}
