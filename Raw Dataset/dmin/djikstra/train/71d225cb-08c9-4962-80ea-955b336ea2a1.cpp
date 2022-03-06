#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int n;

int nr[1502],viz[1502];

double dist[1502];



vector <pair<int, double> > v[1502];



inline int cmp(double a,double b)

{

    if(a>b+0.0000000001)

        return 1;

    if(a+0.0000000001<b)

        return -1;

    return 0;

}





int main()

{

    freopen("dmin.in","r",stdin);

    freopen("dmin.out","w",stdout);

    int i,j,m,nod,x,y;

    double c,mini;

    scanf("%d%d",&n,&m);

    for(i=1;i<=m;++i)

    {

        scanf("%d%d%lf",&x,&y,&c);



        v[x].push_back(make_pair(y,log(c)));

        v[y].push_back(make_pair(x,log(c)));

    }



    for(i=2;i<=n;++i)

        dist[i]=(1<<30);



    nr[1]=1;

   dist[1]=0;



    for(i=1;i<=n;++i)

    {

        mini=(1<<30);

        for(j=1;j<=n;++j)

            if(!viz[j] && dist[j]<mini)

            {

                mini=dist[j];

                nod=j;

            }



        if(cmp(mini,(double)(1<<30))==0)

            break;

        viz[nod]=1;



        for(j=0;j<v[nod].size();++j)

        {

            if(cmp(dist[v[nod][j].first] , dist[nod]+v[nod][j].second)==0)

                nr[v[nod][j].first]=(nr[v[nod][j].first]+nr[nod]) % 104659;

            else if(cmp(dist[v[nod][j].first] , dist[nod]+v[nod][j].second)==1)

            {

                dist[v[nod][j].first]=dist[nod]+v[nod][j].second;

                nr[v[nod][j].first]=nr[nod];

            }

        }



    }



    for(i=2;i<=n;++i)

        printf("%d ",nr[i]%104659);

    printf("\n");



    return 0;

}
