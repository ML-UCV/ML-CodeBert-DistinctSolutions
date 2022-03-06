#include <bits/stdc++.h>
using namespace std;

ifstream r("stramosi.in");

ofstream w("stramosi.out");

int n,m,stramos[20][250002];

int main()

{

    r>>n>>m;

    for(int i=1; i<=n; i++){

        r>>stramos[0][i];

    }

    for(int i=1,p=2; p<=n; i++,p*=2){

        for(int j=1; j<=n; j++){

            stramos[i][j]=stramos[i-1][stramos[i-1][j]];

        }

    }

    while(m--)

    {

        int p,q;

        r>>q>>p;

        while(p!=0)

        {

            int k=__builtin_ctz(p);

            q=stramos[k][q];

            p-=1<<k;

        }

        w<<q<<"\n";

    }

    return 0;

}
