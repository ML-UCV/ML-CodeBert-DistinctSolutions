#include <bits/stdc++.h>


using namespace std;

ifstream in("stramosi.in");

ofstream out("stramosi.out");

int n,m;

int dp[250005][19];

int lg(int x)

{

    int nr=0;

    while(x)

    {

        nr++;

        x/=2;

    }

    return nr-1;

}

int query(int poz, int nod)

{

    for(int i=0; (1<<i)<=poz; i++)

    {

        if(poz&(1<<i))

        {

            nod=dp[nod][i];

            if(nod==0)

                return 0;

        }

    }

    return nod;

}

int main()

{

    in >> n >> m;

    for(int i=1; i<=n; i++)

    {

        in >> dp[i][0];

    }

    int p=1;

    for(int i=1; i<=n; i++)

    {

        for(int j=1; j<18; j++)

        {

            dp[i][j]=dp[dp[i][j-1]][j-1];

        }

    }

    for(int i=1; i<=m; i++)

    {

        int x,poz;

        in >> x >> poz;

        out << query(poz,x) << '\n';

    }

    return 0;

}
