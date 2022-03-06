#include <fstream>


using namespace std;

ifstream f("stramosi.in");

ofstream g("stramosi.out");

int n,m,a[50][250001],log[250001],i,j,q,p;

int main()

{

    f>>n>>m;

    for(i=1; i<=n; i++)

    {

        f>>a[0][i];

    }

    for(i=1; (1<<i)<=n; i++)

        for(j=1; j<=n; j++)

        {

            a[i][j]=a[i-1][a[i-1][j]];

        }

    for(i=2; i<=n; i++)

        log[i]=log[i/2]+1;

    for(i=1;i<=m;i++)

    {

        f>>q>>p;

        int ans;

        while(p>0)

        {

            int x=log[p];

            q=a[x][q];

            p-=(1<<x);

        }

        g<<q<<'\n';

    }

    return 0;

}
