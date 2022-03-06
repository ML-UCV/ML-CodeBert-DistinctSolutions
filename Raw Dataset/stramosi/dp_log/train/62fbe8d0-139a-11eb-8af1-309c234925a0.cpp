#include <fstream>


using namespace std;

ifstream f("stramosi.in");

ofstream g("stramosi.out");

int n,q,i,x,nrstr,nr,stramos[18][250000],j,pas,solst,sol;

int main()

{

    f>>n>>q;

    for (i=1;i<=n;i++)

    {

        f>>x;

        stramos[0][i]=x;

    }

    for (i=1;(1<<i)<=n;i++)

    {

        for (j=1;j<=n;j++)

        {

            stramos[i][j]=stramos[i-1][stramos[i-1][j]];

        }

    }

    for (i=1;i<=q;i++)

    {

        f>>nr>>nrstr;pas=18;sol=0;solst=nr;

        while (pas>=0)

        {

            if (sol+(1<<pas)<=nrstr)

            {

                solst=stramos[pas][solst];sol+=(1<<pas);

            }

            pas--;

        }

        g<<solst<<'\n';

    }

    return 0;

}
