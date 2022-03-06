#include <bits/stdc++.h>


using namespace std;

ifstream f("stramosi.in");

ofstream g("stramosi.out");

const int N = 19;

const int M = 250001;

int n,m,stramos[N][M];

int main()

{

    f>>n>>m;

    for(int i=1; i<=n; i++)

        f>>stramos[0][i];

    for(int i=1,p=2;p<=n;i++,p*=2)

        for(int j=1;j<=n;j++)

            stramos[i][j]=stramos[i-1][stramos[i-1][j]];

    for(;m;m--)

    {

        int p,q;

        f>>q>>p;

        while(p)

        {

            int k=__builtin_ctz(p);

            q=stramos[k][q];

            p-=1<<k;

        }

        g<<q<<'\n';

    }

    return 0;

}
