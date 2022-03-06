#include <bits/stdc++.h>


using namespace std;

ifstream f("stramosi.in");

ofstream g("stramosi.out");

int N,M,a,rmq[19][250005],lev,nod;



int main()

{

    f>>N>>M;

    for(int i=1;i<=N;i++)

    {

        f>>a;

        rmq[0][i]=a;

    }

    for(int i=1;(1<<i)<=N;i++)

    for(int j=1;j<=N;j++)

    rmq[i][j]=rmq[i-1][rmq[i-1][j]];



    for(int i=1;i<=M;i++)

    {

        f>>nod>>lev;

        int org=lev;

        while(lev)

        {

            lev&=lev-1;

            int dif=log2(org-lev);

            nod=rmq[dif][nod];

            org=lev;

        }

        g<<nod<<'\n';

    }

    return 0;

}
