#include<fstream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;







ifstream f("dmin.in");

ofstream g("dmin.out");

struct pairr { int to; double cost; };

pairr mp(int x,double y)

{ pairr c; c.to=x , c.cost=y;

 return c;

}

vector<pairr>a[1501];

double cmin[1501];

bool v[1501];

int way[1501];

queue<int>q;

void BF()

{ int i,k,j; double co;

 q.push(1); v[1]=true;

 cmin[1]=0.00; way[1]=1;

 while(!q.empty())

 { i=q.front(); q.pop(); v[i]=false;

  for(k=0;k<a[i].size();k++)

  { j=a[i][k].to , co=a[i][k].cost;

   if(cmin[j]-cmin[i]-co>1e-10)

   { cmin[j]=cmin[i]+co;

    way[j]=way[i];

    if(v[j]==false)

    { q.push(j);

     v[j]=true;

    }

   }else if(cmin[i]+co-cmin[j]<=1e-10)

     way[j]=(way[j]%104659 +way[i]%104659)%104659;

  }

 }

}

int main()

{ int i,j,x,y,N,M; double c;

 f>>N>>M;

 for(i=1;i<=M;i++)

 { f>>x>>y>>c;

  a[x].push_back(mp(y,log(c)));

  a[y].push_back(mp(x,log(c)));

 }

 for(i=1;i<=N;i++) cmin[i]=1000000.000;

 BF();

 for(i=2;i<=N;i++)

  g<<way[i]<<" ";

 f.close();

 g.close();

 return 0;

}
