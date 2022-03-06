#include <bits/stdc++.h>




using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

int n,m,i,j,p,q,d[25][250010];

int main() {

    fin>>n>>m;

    for (i=1;i<=n;i++)

        fin>>d[0][i];

    for (i=1;i<=20;i++)

        for (j=1;j<=n;j++)

            d[i][j]=d[i-1][d[i-1][j]];

    while (m--) {

        fin>>q>>p;

        for (i=0;(1<<i)<=p;i++)

            if (p&(1<<i))

                q=d[i][q];

        fout<<q<<"\n";

    }

    return 0;

}
