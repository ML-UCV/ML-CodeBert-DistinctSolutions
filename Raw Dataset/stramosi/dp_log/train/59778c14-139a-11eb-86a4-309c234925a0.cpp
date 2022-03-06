#include <bits/stdc++.h>


using namespace std;

ifstream f("stramosi.in");

ofstream g("stramosi.out");

int N,M,P,Q,x,rmq[20][250001];



int main()

{

    f>>N>>M;

    for(int i=1;i<=N;i++)

    {

        f>>x;

        rmq[0][i]=x;

    }



    for(int i=1;i<=log2(N);i++)

    for(int j=1;j<=N;j++)

    rmq[i][j]=rmq[i-1][rmq[i-1][j]];



    for(int i=1;i<=M;i++)

    {

        f>>Q>>P;

        int nod=Q;

        while(P)

        {

            int poz = P & -P;

            P&=P-1;

            int dif=log2(poz);

            nod=rmq[dif][nod];

        }

        g<<nod<<'\n';

    }



    return 0;

}
