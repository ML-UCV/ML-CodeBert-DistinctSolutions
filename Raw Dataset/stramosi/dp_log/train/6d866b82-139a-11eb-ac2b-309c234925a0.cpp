#include <bits/stdc++.h>


using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int n, m, p, q;

int TT[25][250001];



int main()

{

    fin>>n>>m;

    for(int i=1; i<=n; ++i) fin>>TT[0][i];

    for(int k=1; (1<<k)<=n; ++k)

    {

        for(int j=1; j<=n; ++j) TT[k][j]=TT[k-1][TT[k-1][j]];

    }
    for(int i=1; i<=m; ++i)

    {

        fin>>q>>p;

        int exp=0;

        while(p>0)

        {

            if(p%2==1) q=TT[exp][q];

            ++exp;

            p=p/2;

        }

        fout<<q<<"\n";

    }

    return 0;

}
