#include <fstream>


using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



const int maxi=250001;

int d[18][maxi];



int main()

{

    ios::sync_with_stdio(false);

    int n,m,i,j,q,p;

    fin>>n>>m;

    for(i=1; i<=n; i++)

        fin>>d[0][i];

    for(i=1; i<18; i++)

        for(j=1; j<=n; j++)

            d[i][j]=d[i-1][d[i-1][j]];



    for(i=0; i<m; i++)

    {

        fin>>q>>p;

        j=0;

        while(p!=0)

        {

            if(p%2!=0)

                q=d[j][q];

            p/=2;

            j++;

        }

        fout<<q<<'\n';

    }

    fin.close();

    fout.close();

    return 0;

}
