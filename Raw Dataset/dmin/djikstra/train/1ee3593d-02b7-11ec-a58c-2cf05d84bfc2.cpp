#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<bitset>
#include<math.h>
using namespace std;



struct nod {

 int y;

 double cost;

 inline nod(int _y, double _cost) {

  y=_y;

  cost=_cost;

 }

 inline bool operator < (const nod &c) const {

  return (double)cost>c.cost;

 }

};

priority_queue <nod> c;

vector <nod> v[1501];

int pos[1501];

double d[1501];

bitset <1501> p;

inline double modul(double x)

{

 if(x<0)

  return -x;

 return x;

}

void dijkstra()

{

 int x;

 c.push(nod(1,0));

 while(c.empty()==0) {

  x=c.top().y;

  c.pop();

  if(p[x]==0) {

   p[x]=1;

   for(vector <nod> :: iterator it=v[x].begin();it!=v[x].end();it++)

    if(it->y!=1) {

    if((double)d[it->y]-d[x]-it->cost>0.0000000001) {

     d[it->y]=(double)d[x]+it->cost;

     pos[it->y]=(pos[x])%104659;

     c.push(nod(it->y,d[it->y]));

    }

    else if(modul(d[it->y]-d[x]-it->cost)<=0.0000000001) {

     pos[it->y]=(pos[it->y]+pos[x])%104659;

     c.push(nod(it->y,d[it->y]));

    }

    }

  }

 }

}

int main ()

{

 int i,n,m,x,y;

 double cost;

 ifstream f("dmin.in");

 ofstream g("dmin.out");

 f>>n>>m;

 for(i=1;i<=m;i++) {

  f>>x>>y>>cost;

  cost=log(cost);

  v[x].push_back(nod(y,cost));

  v[y].push_back(nod(x,cost));

 }

 f.close();

 for(i=1;i<=n;i++)

  d[i]=2147000000;

 d[1]=1;

 pos[1]=1;

 dijkstra();

 for(i=2;i<=n;i++)

  g<<pos[i]%104659<<" ";

 g.close();

 return 0;

}
