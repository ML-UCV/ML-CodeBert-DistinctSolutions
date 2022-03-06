#include <iostream>
#include <fstream>


using namespace std;



ifstream f("stramosi.in");

ofstream g("stramosi.out");



int n, m;



int stra[20][250005];



int main()

{

    f>>n>>m;



    for(int i = 1; i <= n; i++)

    {

        f>>stra[0][i];

    }



    for(int i = 1; (1<<i)<=n; i++)

        for(int nod = 1; nod <= n; nod++)

        {

            stra[i][nod] = stra[i-1][stra[i-1][nod]];

        }



    int nod,p;

    for(int i = 1; i <= m; i++)

    {

        f>>nod>>p;

        for(int pu=0; pu <= 20; pu++)

        {

            if((1<<pu) & p)

                nod = stra[pu][nod];

        }

        g<<nod<<'\n';

    }

    return 0;

}
