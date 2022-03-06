#include<bits/stdc++.h>
using namespace std;

double dp[1505];

vector<pair<int,double> > v[1505];

int pos[1505],n,m,x,y,c;

typedef struct edge

{

  int nod;

  double cost;

  bool operator<(const edge& other) const

  {

    return cost>other.cost;

  }

};

priority_queue<edge> q;

void Dijkstra()

{

    while(!q.empty())

    {

        int x=q.top().nod;

        double y=q.top().cost;



        q.pop();

        for(vector<pair<int,double> >::iterator it=v[x].begin();it!=v[x].end();it++)

        {

            double newcost=y+(*it).second;

            if((dp[(*it).first]-1e-9)>newcost)

            {

                dp[(*it).first]=newcost;

                pos[(*it).first]=pos[x];

                q.push({(*it).first,dp[(*it).first]});

            }

                else

            if(fabs(newcost-dp[(*it).first])<=1e-9)

            {

                pos[(*it).first]=(pos[(*it).first]+pos[x])%104659;

            }

        }

    }

}

int main()

{

    freopen("dmin.in","r",stdin);

    freopen("dmin.out","w",stdout);

    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++)

    {

        scanf("%d%d%d",&x,&y,&c);

        v[x].push_back(make_pair(y,log2(c)));

        v[y].push_back(make_pair(x,log2(c)));

    }

    dp[1]=0;

    for(int i=2;i<=n;i++) dp[i]=1.0*INT_MAX;

    pos[1]=1;

    q.push({1,0});

    Dijkstra();

    for(int i=2;i<=n;i++) printf("%d ",pos[i]);

    return 0;

}
