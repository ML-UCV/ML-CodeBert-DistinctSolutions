#include <fstream>
#include <climits>
using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

int n,m;

int d[20][250001];

int main()

{

    fin>>n>>m;

    for(int i=1;i<=n;i++)

        fin>>d[0][i];

    for(int i=1;(1<<i)<=n;i++)

    {

        for(int j=1;j<=n;j++)

        {

            d[i][j]=d[i-1][d[i-1][j]];

        }

    }

    for(int i=1;i<=m;i++)

    {

        int x, nr;

        fin>>x>>nr;

        int t=x;

        while(nr!=0)

        {

            int j=1,p=0;

            while(j*2<=nr)

                j=j*2,p++;

            t=d[p][t];

            nr-=j;

        }

        fout<<t<<'\n';

    }

    return 0;

}
