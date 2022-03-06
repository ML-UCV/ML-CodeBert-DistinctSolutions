#include <fstream>


using namespace std;

ifstream in("stramosi.in");

ofstream out("stramosi.out");

long long ma[30][250100];

int main()

{

    long long n,m,p,q;

    int i,j;

    in>>n>>m;

    for(i=1; i<=n; i++)

    {

        in>>ma[0][i];

    }

    for(i=1; (1<<i)<=n; i++)

    {

        for(j=1; j<=n; j++)

        {

            ma[i][j]=ma[i-1][ma[i-1][j]];

        }

    }

    while(m--)

    {

        in>>q>>p;

        int ok=0;

        while(p)

        {

            if(p%2==1)

            {

                q=ma[ok][q];

            }

            ok++;

            p/=2;

        }

        out<<q<<'\n';

    }

    return 0;

}
