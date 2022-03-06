#include <fstream>


using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

const int NMAX=250000;

const int logmax=20;

int str2put[NMAX+5][logmax+5];
int main()

{

    int n, m, sol, i, j, exp, put2, q, p;

    fin>>n>>m;

    for(i=1;i<=n;i++)

      fin>>str2put[i][0];

    for(i=1;i<=n;i++)

    {

        for(j=1;j<=20;j++)

        {

            if(str2put[i][j-1]!=0 and (1<<j)<=n)

                str2put[i][j]=str2put[str2put[i][j-1]][j-1];

        }

    }

    for(i=1;i<=m;i++)

    {

        fin>>q>>p;

        put2=1;

        exp=0;

        while(put2<=p)

        {

            if(put2&p)

                q=str2put[q][exp];

            put2=put2*2;

            exp++;

        }

        fout<<q<<"\n";

    }

    return 0;

}
