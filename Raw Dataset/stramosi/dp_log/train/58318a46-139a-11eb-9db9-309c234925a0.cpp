#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

int n,i,m,p,q,j,ex;

int mat[19][250001],stramos;

int main()

{

    fin>>n>>m;

    for(i=1; i<=n; i++)

    {

        fin>>mat[0][i];

    }

    for(j=1;j<=18;j++)

    {

        for(i=1;i<=n;i++)

            mat[j][i]=mat[j-1][mat[j-1][i]];

    }

    while(m--)

    {

        fin>>q>>p;

        stramos=q;

        ex=0;

        while(p)

        {

            if(p%2==1)

                stramos=mat[ex][stramos];

            p>>=1;

            ex++;

        }

        fout<<stramos<<"\n";

    }

}
