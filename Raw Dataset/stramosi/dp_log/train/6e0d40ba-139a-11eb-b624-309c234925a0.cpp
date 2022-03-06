#include <fstream>
using namespace std;

ifstream in("stramosi.in");

ofstream out("stramosi.out");

int log[250001];

int d[18][250001];

int main()

{

    int n,m,i,j,p,q,x;

    in>>n>>m;

    for(i=2; i<=250000; i++)

        log[i]=1+log[i/2];

    for(i=1; i<=n; i++)

    {

        in>>x;

        for(j=0; j<=log[n]; j++)

        {

            if(j==0)

                d[0][i]=x;

            else

                d[j][i]=d[j-1][d[j-1][i]];

        }

    }

    int pas;

    for(i=1; i<=m; i++)

    {

        pas=1<<17;

        in>>p>>q;

        while(q)

        {

            if(q-pas>=0)

            {

                p=d[log[pas]][p];

                q-=pas;

            }

            pas/=2;

        }

        out<<p<<'\n';

    }

    return 0;

}
