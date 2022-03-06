#include <bits/stdc++.h>


using namespace std;



ifstream f("stramosi.in");

ofstream g("stramosi.out");



int n,m,i,stramos,t,query,pas,k,tata[250100],d[20][250100];



int main()

{

    f>>n>>m;

    for(i=1;i<=n;i++)

    {

        f>>tata[i];

        d[0][i]=tata[i];

    }







    for(k=1;(1<<k)<=n;k++)

    {

        for(i=1;i<=n;i++)

        {

            d[k][i] = d[k-1][d[k-1][i]];

        }

    }





    for(query=1;query<=m;query++)

    {

        f>>i>>t;



        stramos=i;





        pas=0;

        while(t)

        {

            if(t%2==1)

            {



                stramos=d[pas][stramos];

            }

            pas++;

            t=t/2;

        }



        g<<stramos<<'\n';

    }



    return 0;

}
