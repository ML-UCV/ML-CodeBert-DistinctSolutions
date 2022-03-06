#include <iostream>
#include <fstream>
using namespace std;

ifstream f("stramosi.in");

ofstream g("stramosi.out");

int N,M,Q,P;

int x,v[25][250005],rez;

int main()

{

    f>>N>>M;

    for(int i=1; i<=N; i++)

    {

        f>>x;

        v[0][i]=x;

    }

    for(int i=1; i<=18; i++)

        for(int j=1; j<=N; j++)

            if(v[i-1][j] and (1<<i)<=N)

        v[i][j]=v[i-1][v[i-1][j]];
    for(int i=1; i<=M; i++)

    {

        f>>Q>>P;

        for(int j=0; j<=18; j++)

        {

        if ((1<<j) & P)

        Q=v[j][Q];

        }

        g<<Q<<"\n";

    }

}
