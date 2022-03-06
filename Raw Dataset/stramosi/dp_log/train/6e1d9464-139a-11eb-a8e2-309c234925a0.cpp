#include <fstream>


using namespace std;

ifstream in("stramosi.in");

ofstream out("stramosi.out");



const int N=250001;

const int LOG=17;

int n,m,log2[N],s[LOG][N];



int main()

{

    in>>n>>m;

    for(int i=2;i<=n;i++)

        log2[i]=1+log2[i/2];

    for(int i=1;i<=n;i++)

    {

        in>>s[0][i];

    }

    for(int i=1;i<=log2[n];i++)

        for(int j=1;j<=n;j++)

            s[i][j]=s[i-1][s[i-1][j]];

    int q,p,poz,k;

    for(int i=1;i<=m;i++)

    {

        in>>q>>p;

        poz=17;

        while(p>0 && poz>=0)

        {

            k=1<<poz;

            if(k<=p)

            {

                q=s[poz][q];

                p=p-k;

            }

            poz--;

        }

        out<<q<<'\n';

    }

    return 0;

}
