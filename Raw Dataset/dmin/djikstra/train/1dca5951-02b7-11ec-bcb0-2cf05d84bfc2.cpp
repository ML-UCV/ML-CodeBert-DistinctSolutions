#include<fstream>
#include<vector>
#include<queue>
#include<cmath>




using namespace std;



int i,j,n,m;

bool viz[1501];

unsigned long x,y,nr[1501];

double cost1,d[1501];

struct muchie

{

    int nod;

 double cost;

};

vector<muchie> a[1501];

void dijkstra(int x)

{

    int i;

    queue<int> q;

    q.push(x);

    d[x]=1;

    nr[x]=1;

    while(!q.empty())

    {

        x=q.front();

  viz[x]=0;

        for(i=0;i<a[x].size();++i)

        {

        if(d[a[x][i].nod]-d[x]-a[x][i].cost>0.0000000001)

        {

            d[a[x][i].nod]=d[x]+a[x][i].cost;

            nr[a[x][i].nod]=nr[x];

   if(!viz[a[x][i].nod])

            q.push(a[x][i].nod),viz[a[x][i].nod]=1;

        }

        else

        if(fabs(d[a[x][i].nod]-d[x]-a[x][i].cost)<=0.0000000001)

  {

            nr[a[x][i].nod]=(nr[a[x][i].nod]+nr[x])%104659;

   if(nr[a[x][i].nod]>104659)

   {

    nr[a[x][i].nod]-=104659;

    if(!viz[a[x][i].nod])

     q.push(a[x][i].nod),viz[a[x][i].nod]=1;

   }

  }

        }

        q.pop();

    }

}

int main()

{

    ifstream f("dmin.in");

    ofstream g("dmin.out");

    f>>n>>m;

    for(i=1;i<=m;++i)

    {

        f>>x>>y>>cost1;

  cost1=log(cost1);

        a[x].push_back((muchie) {y,cost1});

        a[y].push_back((muchie) {x,cost1});

    }

    for(i=1;i<=n;++i)

    d[i]=1<<20,nr[i]=0;

    dijkstra(1);

 for(i=2;i<=n;++i)

  g<<nr[i]%104659<<" ";

    return 0;

}
