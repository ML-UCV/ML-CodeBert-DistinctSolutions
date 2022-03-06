#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;



int nr,n,m,p[110],stop=1;

struct mnp

{

    int x,y,z;

}a[1010];

int main()

{

    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);

    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)

        p[i]=1;

    for(int i=1;i<=m;i++)

    {

        int d,b,c;

        scanf("%d%d%d",&d,&b,&c);

        a[i].x=d;

        a[i].y=b;

        a[i].z=c;

    }

    while (stop)

    {

        stop=0;

        for(int i=1;i<=m;i++)

        {

            int r=a[i].x,s=a[i].y,q=a[i].z;

            if(q==0 && p[r]==0 && p[s]==0)

            {

                p[r]=1;p[s]=1;

                stop=1;

                break;

            }

            if(q==1 && p[r]==0 && p[s]!=0)

            {

                p[s]=0;

                stop=1;

                break;

            }

            if(q==2 && p[r]!=0 && p[s]==0)

            {

                p[r]=0;

                stop=1;

                break;

            }

            if(q==3 && p[r]!=0 && p[s]!=0)

            {

                p[s]=0;

                stop=1;

                break;

            }

        }

    }

    for(int i=1;i<=n;i++)

        if(p[i]) nr++;

    printf("%d\n",nr);

    for(int i=1;i<=n;i++)

        if(p[i]) printf("%d\n",i);

    return 0;

}
