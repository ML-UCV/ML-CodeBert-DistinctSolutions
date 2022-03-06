#include <iostream>
#include <fstream>
using namespace std;



ofstream fo("stramosi.out");

ifstream fi("stramosi.in");



int n,m,str[23][250000],a,b;



int main()

{

    fi>>n>>m;



    for(int i=1;i<=n;i++)

    {

        fi>>a;

        str[0][i]=a;

    }





    for(int i=1;(1<<i)<=n;i++)

    {

        for(int j=1;j<=n;j++)

        {

            str[i][j]=str[i-1][ str[i-1][j] ] ;

        }

    }



    for(int i=1;i<=m;i++)

    {

        fi>>a>>b;



        for(int i=0;i<=20;i++)

        {

            if( (1<<i)& b )

                a=str[i][a];

        }

        fo<<a<<'\n';



    }





   fo.close();

   fi.close();

    return 0;

}
