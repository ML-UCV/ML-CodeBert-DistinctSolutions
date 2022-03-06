#include <fstream>
#include <cstring>


using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



int k,q,nr,n,m,urm[2000005],v[1005];

char N[2000005],M[2000005];



int main()

{

    int i;

    f.getline(N,2000005);

    f.getline(M,2000005);

    k=0;n=strlen(N);urm[1]=0;

    for (i=2;i<=n;i++)

    {

        while (k>0 && N[k]!=N[i-1]) k=urm[k];

        if (N[k]==N[i-1]) k++;

        urm[i]=k;

    }

    q=0;nr=0;m=strlen(M);

    for (i=0;i<m;i++)

    {

        while (q>0 && N[q]!=M[i]) q=urm[q];

        if (N[q]==M[i]) q++;

        if (q==n)

        {

            nr++;

            if (nr<=1000) v[nr]=i-n+1;

        }

    }

    g<<nr<<'\n';

    if (nr>=1000) nr=1000;

    for (i=1;i<=nr;i++) g<<v[i]<<" ";

    return 0;

}
