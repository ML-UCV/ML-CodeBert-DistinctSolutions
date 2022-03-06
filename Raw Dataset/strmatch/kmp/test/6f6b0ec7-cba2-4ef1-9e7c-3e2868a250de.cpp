#include <fstream>
#include <cstring>
using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

int n,m,i,j,k,urm[2000005],nr,poz[1001];

char vn[2000005],vm[2000005];

int main()

{

    f.getline(vn,2000005);

    f.getline(vm,2000005);

    k=0;

    n=strlen(vn);

    m=strlen(vm);

    urm[1]=0;

    for(i=2;i<=n;i++)

    {

        while(k>0 && vn[k]!=vn[i-1]) k=urm[k];

        if(vn[k]==vn[i-1]) k++;

        urm[i]=k;

    }

    k=0;

    for(i=0;i<m;i++)

    {

        while(k>0 && vn[k]!=vm[i]) k=urm[k];

        if(vn[k]==vm[i]) k++;

        if(k==n)

        {

            nr++;

            if(nr<=1000)poz[nr]=i-n+1;

        }

    }

    g<<nr<<'\n';

    if(nr>1000) nr=1000;

    for(i=1;i<=nr;i++)

        g<<poz[i]<<" ";

}
