#include <fstream>


using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

const int N=30001;

int concurent[N],v[N],nr[1<<16],n,poz;



void prelucrare(int p,int st,int dr)

{

    if(st==dr)

    {

        concurent[st]=poz;

        nr[p]++;

        return;

    }

    int m=(st+dr)/2;

    if(m-st+1-nr[2*p]>=v[poz])

    {

        prelucrare(2*p,st,m);

    }

    else

    {

        v[poz]-=m-st+1-nr[2*p];

        prelucrare(2*p+1,m+1,dr);

    }

    nr[p]++;

}

int main()

{

    fin>>n;

    for(int i=1;i<=n;i++)

       fin>>v[i];

    for(int i=n;i>=1;i--)

    {

        poz=i;

        prelucrare(1,1,n);

    }

    for(int i=1;i<=n;i++)

       fout<<concurent[i]<<"\n";

    return 0;

}
