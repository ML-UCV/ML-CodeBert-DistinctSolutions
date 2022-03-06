#include<stdio.h>
#include<set>
#include<math.h>
#include<vector>
using namespace std;
int n,m,nrsol[2005];

double dist[2005];

vector<int> v[2005];

vector<double> cost[2005];



int comp(double a,double b)

{

    if(a-0.0000001>b) return 1;

    if(b-0.0000001>a) return -1;

    return 0;

}



class cmp

{

public:

    bool operator()(const int& a,const int& b)

    {

        if(!comp(dist[a],dist[b]))

            return a<b;

        return dist[a]<dist[b];

    }

};



set<int,cmp> myset;





void dijkstra()

{

    int i,j,p,lim,vec,r;



    for(i=1;i<=n;i++)

        dist[i]=200000000;

    dist[1]=0;

    nrsol[1]=1;

    for(i=1;i<=n;i++)

        myset.insert(i);

    for(i=1;i<=n;i++)

    {

        if(myset.size()==0)

            break;

        p=*myset.begin();

        myset.erase(myset.begin());

        lim=v[p].size();

        for(j=0;j<lim;j++)

        {

            vec=v[p][j];

            r=comp(dist[p]+cost[p][j],dist[vec]);

            if(r<0)

            {

                myset.erase(vec);

                dist[vec]=dist[p]+cost[p][j];

                nrsol[vec]=nrsol[p];

                myset.insert(vec);

            }

            else if(!r)

            {

                nrsol[vec]+=nrsol[p];

                if(nrsol[vec]>=104659)

                    nrsol[vec]-=104659;

            }

        }

    }

}



int main ()

{

    int i,a,b,c;

    double val;



    freopen("dmin.in","r",stdin);

    freopen("dmin.out","w",stdout);

    scanf("%d%d",&n,&m);

    for(i=1;i<=m;i++)

    {

        scanf("%d%d%d",&a,&b,&c);

        v[a].push_back(b);

        v[b].push_back(a);

        val=log(c);

        cost[a].push_back(val);

        cost[b].push_back(val);

    }

    dijkstra();

    for(i=2;i<=n;i++)

        printf("%d ",nrsol[i]);

    printf("\n");

    return 0;

}
