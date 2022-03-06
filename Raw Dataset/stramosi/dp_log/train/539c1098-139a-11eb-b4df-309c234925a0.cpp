#include <iostream>
#include <fstream>


using namespace std;



ifstream fin ("stramosi.in");

ofstream fout ("stramosi.out");



int tt[250001];

int d[18][250001];



int main()

{

    int n, m, i, p, log;

    fin>>n>>m;



    for(i=1; i<=n; i++)

    {

        fin>>d[0][i];

    }



    log=0;

    while( (1<<log)<=n )

    {

        log++;

    }

    log--;





    for(p=1; p<=log; p++)

    {

        for(i=1; i<=n; i++)

        {

            d[p][i]=d[p-1][ d[p-1][i] ];

        }

    }



    for(i=1; i<=m; i++)

    {

        int nod, x;

        fin>>nod>>x;



        for(p=0; p<=log; p++)

        {

            if( (1<<p) & x )

            {

                nod=d[p][nod];

            }

        }



        fout<<nod<<"\n";

    }

}
