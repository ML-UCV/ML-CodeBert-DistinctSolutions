#include<vector>
#include<queue>#include <stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;





typedef pair <int,double> p;



int n,m,i;

int x,y,z;

double zLg;



vector <p> g[1505];

vector <p> ::iterator it;

bool ut[1505];

double cost[1505];

int nr[1505];



struct cmp

{

 bool operator () (const int &i,const int &j) const

 {

  return (cost[i]-cost[j])>1e-10;

 }

};

priority_queue <int,vector <int>,cmp> Q;



double modul(double x)

{

 if(x<0)

  return -x;

 return x;

}

void Dijkstra()

{

 for(i=1;i<=1505;i++)

  cost[i]=2000000000.5;

 cost[1]=0;

 Q.push(1);



 while(!Q.empty())

 {

  int nod=Q.top();

  Q.pop();

  ut[nod]=0;



  for(it=g[nod].begin();it!=g[nod].end();it++)

  {

   if((cost[it->first]-cost[nod]-it->second)<1e-10)

    continue;



   cost[it->first]=cost[nod]+it->second;



   if(!ut[it->first])

   {

    ut[it->first]=1;

    Q.push(it->first);

   }

  }

 }

}



int main()

{

 freopen("dmin.in","r",stdin);

 freopen("dmin.out","w",stdout);



 scanf("%d%d",&n,&m);

 for(i=1;i<=m;i++)

 {

  scanf("%d%d%d",&x,&y,&z);

  zLg=log(z);

  g[x].push_back(p(y,zLg));

  g[y].push_back(p(x,zLg));

 }



 Dijkstra();



 nr[1]=1;

 for(i=1;i<=n;i++)

  Q.push(i);



 while(!Q.empty())

 {

  int nod=Q.top();

  Q.pop();

  for(it=g[nod].begin();it!=g[nod].end();it++)

  {

   if(modul(cost[it->first]-cost[nod]-it->second)<1e-10)

    nr[it->first]=(nr[it->first]+nr[nod])%104659;

  }

 }



 for(i=2;i<=n;i++)

  printf("%d ",nr[i]);



 return 0;

}
