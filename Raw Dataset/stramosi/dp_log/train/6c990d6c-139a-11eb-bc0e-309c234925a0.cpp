#include <iostream>
#include <fstream>


std::ifstream in("stramosi.in");

std::ofstream out("stramosi.out");



using namespace std;

int t[20][250005];

int numar,nrst,n,m;



int main()

{

    in>>n>>m;

    for(int i=1;i<=n;i++)

    {

        in>>t[0][i];

    }

    for(int i=1;(1<<i)<=n;i++)

    {

        for(int k=1;k<=n;k++)

        {

            t[i][k]=t[i-1][t[i-1][k]];

        }

    }

    for(int i=1;i<=m;i++)

    {

        in>>numar>>nrst;

        for(int k=0;k<=20;k++)

        {

            if((1<<k)&nrst)

            {

                numar=t[k][numar];

            }

        }

        out<<numar<<"\n";

    }

    return 0;

}
