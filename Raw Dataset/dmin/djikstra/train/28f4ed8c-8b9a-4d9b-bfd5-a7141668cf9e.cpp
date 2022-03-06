#include<fstream>
#include<vector>
#include<queue>
#include<bitset>
#include<math.h>


using namespace std;

int n,m,i,j,drum[1501],x,y;

double z,d[1501],eps=1e-10;

struct planeta

{

 int nod;

 double cost;

};

vector<planeta> a[1501];

queue<int>q;

bool uz[1501];

void dijkstra(int x)

{

 int i;

 q.push(x);

 d[x]=0.00000;

 drum[x]=uz[x]=1;

 while(!q.empty())

    {

        x=q.front();

        q.pop();

  uz[x]=0;

        for(i=0;i<a[x].size();++i)

        {

            if(fabs(d[a[x][i].nod]-d[x]-a[x][i].cost)<eps)

            {

                drum[a[x][i].nod]+=drum[x];

                if(drum[a[x][i].nod]>104659)

                {

                    drum[a[x][i].nod]%=104659;

     if(!uz[a[x][i].nod])

                    q.push(a[x][i].nod),uz[a[x][i].nod]=1;

                }

            }

            if(d[a[x][i].nod]-d[x]-a[x][i].cost>eps)

            {

                d[a[x][i].nod]=d[x]+a[x][i].cost;

                drum[a[x][i].nod]=drum[x];

    if(!uz[a[x][i].nod])

                    q.push(a[x][i].nod),uz[a[x][i].nod]=1;

            }

        }

    }

}





int main()

{

 freopen("dmin.in","r",stdin);

 freopen("dmin.out","w",stdout);



 scanf("%d%d",&n,&m);

 for(i=1;i<=m;++i)

 {

  scanf("%d%d%lf",&x,&y,&z);

  z=log(z);

  a[x].push_back((planeta){y,z});

  a[y].push_back((planeta){x,z});

 }

 for(i=2;i<=n;++i)

  d[i]=1000000000;

 dijkstra(1);

 for(i=2;i<=n;++i)

  printf("%d ",drum[i]);



 return 0;

}
