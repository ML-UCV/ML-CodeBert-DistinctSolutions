#include <fstream>


using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



char a[2000001],b[2000001];

int pi[2000001],n,m,nr,poz[2000001];

void make_prefix()

{

    int q=0;

    for (int i=2;i<=m;i++)

    {

        while (q && a[q+1]!=a[i])

            q=pi[q];

        if (a[q+1]==a[i])

            q++;

        pi[i]=q;

    }







}



int main()

{

    fin>>a;

    fin>>b;

    for (;a[m];m++);

    for (;b[n];n++);

    for (int i=m;i>=0;i--)

        a[i]=a[i-1];

    for (int i=n;i>=0;i--)

        b[i]=b[i-1];

    a[0]=b[0]=' ';



    make_prefix();

    int q=0;

    for (int i=1;i<=n;i++)

    {

        while (q && a[q+1]!=b[i])

            q=pi[q];

        if (a[q+1]==b[i])

            q++;

        if (q==m)

        {

            q=pi[m];

            nr++;

            if (nr<=1000)

                poz[nr]=i-m;

        }

    }

    fout<<nr<<'\n';



    for (int i=1;i<=min(1000,nr);i++)

        fout<<poz[i]<<' ';



    return 0;

}
