#include<bits/stdc++.h>






using namespace std;

int n,dp[250010][18 +1],q;

int main()

{

    ifstream fin("stramosi.in");

    ofstream fout("stramosi.out");

    fin>>n>>q;

    for(int i=1;i<=n;++i)

        fin>>dp[i][0];

    for(int i=1;i<=n;++i)

        for(int j=1;j<=18;++j)

            dp[i][j]=dp[dp[i][j-1]][j-1];

    while(q--)

    {

        int d,p;

        fin>>d>>p;

        for(int i=18;i>=0;--i)

            if(p & (1<<i))

                d=dp[d][i];

        fout<<d<<'\n';

    }

    fin.close();

    fout.close();

}
