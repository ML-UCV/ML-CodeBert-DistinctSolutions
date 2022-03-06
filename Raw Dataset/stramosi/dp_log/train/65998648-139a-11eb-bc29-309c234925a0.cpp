#include<bits/stdc++.h>
using namespace std;



ifstream f("stramosi.in");

ofstream g("stramosi.out");



int dp[250001][19],n,m;

int main()

{

    f>>n>>m;

    for(int i=1;i<=n;++i)

    {

        f>>dp[i][0];

    }



    for(int i=1;i<=n;++i)

        for(int j=1;j<=18;++j)

            {

                dp[i][j]=dp[dp[i][j-1]][j-1];

                if(dp[i][j]==0)

                    break;

            }

    for(int i=1;i<=m;++i)

    {

        int x,y,nr=0,node;

        f>>x>>y;

        node=x;

        while(y)

        {

            if(y&1)

            {

                node=dp[node][nr];

            }

            nr++;

            y>>=1;

        }

        g<<node<<'\n';

    }

}
