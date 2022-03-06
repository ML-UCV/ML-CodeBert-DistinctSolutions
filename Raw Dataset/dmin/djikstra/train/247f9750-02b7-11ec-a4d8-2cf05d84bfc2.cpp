#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
vector <pair <int, double> > g[1510];

set <pair <double, int> > t;

int n, m, p[1510];

double d[1510];



void dijkstra()

{

 int i, x;

 double val;

 for (i=1; i<=n; i++) d[i]=1<<30;

 t.insert(make_pair(0,1));

 p[1]=1;

 while (t.size())

 {

  val=(*t.begin()).first;

  x=(*t.begin()).second;

  t.erase(*t.begin());

  for (i=0; i<g[x].size(); i++)

  {

   if (fabs(d[g[x][i].first]-val-g[x][i].second)<0.000001) p[g[x][i].first]=(p[g[x][i].first]+p[x])%104659; else

   if (val+g[x][i].second<d[g[x][i].first])

   {

    d[g[x][i].first]=val+g[x][i].second;

    p[g[x][i].first]=p[x];

    t.insert(make_pair(d[g[x][i].first], g[x][i].first));

   }

  }

 }

}





int main()

{

 freopen("dmin.in","r",stdin);

 freopen("dmin.out","w",stdout);

 scanf("%d %d",&n,&m);

 int i, x, y, c;

 for (i=1; i<=m; i++)

 {

  scanf("%d %d %d",&x,&y,&c);

  g[x].push_back(make_pair(y, log((double) (c))));

  g[y].push_back(make_pair(x, log((double) (c))));

 }

 dijkstra();

 for (i=2; i<=n; i++) printf("%d ",p[i]);

}
