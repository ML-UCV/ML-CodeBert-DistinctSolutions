#include <fstream>


using namespace std;

int t[250005];

int stra[19][250005];

int up(int x, int p)

    {

    for (int i=18;i>=0;i--)

        if (1<<i<=p)

            {

            p-=1<<i;

            x=stra[i][x];

            }

    return x;

    }

int main()

{

    ifstream fin ("stramosi.in");

    ofstream fout ("stramosi.out");

    int n,m,x,p;

    fin>>n>>m;

    for (int i=1;i<=n;i++)

        {

        fin>>t[i];

        stra[0][i]=t[i];

        }

    for (int i=1;i<=18;i++)

        for (int j=1;j<=n;j++)

            stra[i][j]=stra[i-1][stra[i-1][j]];



    for (int i=1;i<=m;i++)

        {

        fin>>x>>p;

        fout<<up(x,p)<<'\n';

        }

    return 0;

}
