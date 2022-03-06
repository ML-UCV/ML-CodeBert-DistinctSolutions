#include <iostream>
#include <fstream>


using namespace std;



ifstream in("stramosi.in");

ofstream out("stramosi.out");



const int maxx=250001;





int main()

{

    int v[18][maxx];

    ios::sync_with_stdio(false);

    int n,m,i,j,q,p;

    in>>n>>m;

    for(i=1; i<=n; i++)

    {

        in>>v[0][i];

    }

    for(i=1; i<18; i++)

    {

        for(j=1; j<=n; j++)

        {

            v[i][j]=v[i-1][v[i-1][j]];

        }

    }

    for(i=0; i<m; i++)

    {

        in>>q>>p;

        j=0;

        while(p!=0)

        {

            if(p%2!=0)

                q=v[j][q];

            p/=2;

            j++;

        }

        out<<q<<'\n';

    }

    return 0;

}
