#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,double> ii;
typedef pair<double,int> iii;

int n,m,i,px1,py1,P[2000];
double cst,D[2000];
vector <ii> e[2000];

inline double absol(double x) {
 return x > 0 ? x : -x;
}

inline int egale(double x,double y) {
 return absol(x - y) <= 1e-6;
}

void dijkstra() {
 for(i = 1; i <= n; i++) D[i] = P[i] = (int)1e9;
 D[1] = 0; P[1] = 1;
 priority_queue < iii,vector<iii>,greater<iii> > Q;
 Q.push(iii(0,1));
 while(!Q.empty()) {
  int nod = Q.top().second;
  double cs = Q.top().first;
  Q.pop();
  if(cs <= D[nod]) {
   for(i = 0; i < (int)e[nod].size(); i++)
    if(egale(D[e[nod][i].first],D[nod] + e[nod][i].second)) {
     P[e[nod][i].first] += P[nod];
     if(P[e[nod][i].first] >= 104659) P[e[nod][i].first] -= 104659;
    }
    else if(D[e[nod][i].first] > D[nod] + e[nod][i].second) {
     D[e[nod][i].first] = D[nod] + e[nod][i].second;
     P[e[nod][i].first] = P[nod];
     Q.push(iii(D[e[nod][i].first],e[nod][i].first));
    }
  }
 }
}

int main() {
 freopen("dmin.in","r",stdin);
 freopen("dmin.out","w",stdout);

 scanf("%d%d",&n,&m);
 for(i = 1; i <= m; i++) {
  scanf("%d%d%lf",&px1,&py1,&cst);
  cst = log(cst);
  e[px1].push_back(make_pair(py1,cst));
  e[py1].push_back(make_pair(px1,cst));
 }

 dijkstra();

 for(i = 2; i <= n; i++) printf("%d ",P[i]);
 printf("\n");

 return 0;
}
