#include <bits/stdc++.h>


using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



const int Nmax=250002;

int n,m;

int puteri[20],lg[Nmax],dp[19][Nmax];



void Build()

{



    for(int i=2;i<Nmax;i++)

        lg[i]=lg[i/2]+1;



    puteri[0]=1;

    for(int i=1;i<=18;i++)

        puteri[i]=2*puteri[i-1];

}



int main()

{

    fin>>n>>m;

    for(int i=1;i<=n;i++)

        fin>>dp[0][i];



    Build();



    for(int i=1;i<=18;i++)

        for(int j=1;j<=n;j++)

            dp[i][j]=dp[i-1][dp[i-1][j]];



    int x,y,sol;

    while(m--)

    {

        fin>>x>>y;



        sol=x;



        while(y)

        {

            x=lg[y];

            sol=dp[x][sol];

            y-=puteri[x];

        }



        fout<<sol<<"\n";

    }

    return 0;

}
