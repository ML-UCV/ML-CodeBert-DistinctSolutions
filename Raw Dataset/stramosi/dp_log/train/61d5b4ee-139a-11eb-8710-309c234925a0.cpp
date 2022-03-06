#include <bits/stdc++.h>


using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

int n,m;

int mat[20][250005];

int v[250005];

int lg2[250005];

int main()

{

    fin>>n>>m;

    for(int i=1;i<=n;++i)

    {

        fin>>v[i];

        mat[0][i]=v[i];

    }

    for(int i=2;i<250005;++i)

        lg2[i]=lg2[i/2]+1;

    for(int i=1;i<=lg2[n];++i)

        for(int j=1;j<=n;++j)

        mat[i][j]=mat[i-1][mat[i-1][j]];

    for(int i=1;i<=m;++i)

    {



        int x,y;

        fin>>x>>y;



        while(y)

        {

            x=mat[lg2[y]][x];

            y=y-(1<<lg2[y]);

        }

        fout<<x<<"\n";

    }

    return 0;

}
