#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

int a[20][250010],N,M,Q,P,Lg[250010];

int main()

{

    int i,j;

    fin>>N>>M;

    for(i=1; i<=N; i++)

    {

        fin>>a[0][i];

    }

    for(i=1; i<=18; i++)

    {

        for(j=1; j<=N; j++)

        {

            a[i][j]=a[i-1][a[i-1][j]];

        }

    }

    for(j=2 ; j<=N ; j++)

        Lg[j] = Lg[j/2]+1;

    for(i=1; i<=M; i++)

    {

        fin>>Q>>P;

        while(P!=0)

        {

            Q=a[Lg[P]][Q];

            P=P-(1<<Lg[P]);

        }

        fout<<Q<<'\n';

    }

}
