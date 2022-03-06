#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<deque>
#include<vector>
using namespace std;

int n,i,j,k,m,x,y,rez[1501];

double dist[1501];

vector<pair<int,double> >v[1501];

deque<int>c;

bool viz[1501];



int main()

{

    freopen("dmin.in","r",stdin);

    freopen("dmin.out","w",stdout);

    scanf("%d %d",&n,&m);

    for (i=1;i<=m;i++)

    {

        double cost;

        scanf("%d %d %lf",&x,&y,&cost);

        cost=log(cost);

        v[x].push_back(make_pair(y,cost));

        v[y].push_back(make_pair(x,cost));

    }

    for(i=2;i<=n;i++) dist[i]=2000000000;

    c.push_back(1);rez[1]=1;viz[1]=true;

    while (!c.empty())

    {

        x=c.front();c.pop_front();viz[x]=false;

        for (j=0;j<v[x].size();j++)

        {

            y=v[x][j].first;

            double cost=v[x][j].second;

            if (0.0000000001<dist[y]-dist[x]-cost)

            {

                dist[y]=dist[x]+cost;

                rez[y]=rez[x];

                if (!viz[y]) c.push_back(y),viz[y]=true;

            }else

                if (0.0000000001>fabs(dist[x]+cost-dist[y]))

                {

                    rez[y]+=rez[x];

                    if (rez[y]>=104659) rez[y]-=104659;

                }

        }

    }

    for (i=2;i<=n;i++) printf("%d ",rez[i]);

    return 0;

}
