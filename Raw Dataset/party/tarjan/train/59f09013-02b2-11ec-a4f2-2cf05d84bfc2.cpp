#include <iostream>
#include <fstream>




using namespace std;

ifstream f("party.in");

ofstream g("party.out");

pair<int,pair<int,int> > a[1010];

int viz[110];

int n,m,ok,i,x,y,op,k;

int main()

{



    f>>n>>m;

    for(i=1; i<=n; i++)

        viz[i]=1;

    for(i=1; i<=m; i++)

        f>>a[i].first>>a[i].second.first>>a[i].second.second;

    while(ok==0)

    {

        ok=1;

        for (i=1; i<=m; i++)

        {

            x=a[i].first;

            y=a[i].second.first;

            op=a[i].second.second;

            if(op==0)

                if(viz[x]==0&&viz[y]==0)

                {

                    viz[x]=1;

                    viz[y]=1;

                    ok=0;

                    break;

                }

            if(op==1)

                if(viz[x]==0&&viz[y]==1)

                {

                    viz[y]=0;

                    ok=0;

                    break;

                }

            if(op==2)

                if(viz[y]==0&&viz[x]==1)

                {

                    viz[x]=0;

                    ok=0;

                    break;

                }

            if(op==3)

                if(viz[x]==1&&viz[y]==1)

                {

                    viz[y]=0;

                    ok=0;

                    break;

                }

        }

    }

    for(i=1; i<=n; i++)

        if(viz[i])k++;

    g<<k<<'\n';

    for(i=1; i<=n; i++)

        if(viz[i])

        g<<i<<'\n';



}
