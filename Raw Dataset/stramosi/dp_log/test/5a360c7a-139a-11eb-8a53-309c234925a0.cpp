#include <bits/stdc++.h>


using namespace std;

ifstream fi("stramosi.in");

ofstream fo("stramosi.out");

int N,M;

int P[250005];

int DP[40][250005];

int query(int nr,int nod)

{



    int k=30;

    while(nr>0)

    {

        if(nr-(1<<k)>=0)

        {

            nr=nr-(1<<k);

            nod=DP[k][nod];

        }

        k--;

    }

    return nod;





}



int main()

{

    fi>>N>>M;

    for(int i=1;i<=N;i++)

    {

        fi>>P[i];

    }

    for(int i=1;i<=N;i++)

    {

        DP[0][i]=P[i];

    }



    for(int k=1;(1<<k)<=N;k++)

    { for(int i=1;i<=N;i++)

            DP[k][i]=DP[k-1][ DP[k-1][i] ];

    }
    for(int Q=1;Q<=M;Q++)

    {

        int nr,nod;

        fi>>nod>>nr;

        fo<<query(nr,nod)<<'\n';

    }



    return 0;

}
