#include <fstream>
#include <string.h>
#include <vector>


using namespace std;

ifstream fin("swap.in");

ofstream fout("swap.out");

char beg[50001];

int sir[50001],arb[3*50001],viz[50001],i,n,poz,pozst,pozdr,ch,nr;

long long sum;

vector <int> G[50];

void upDate(int nod, int st, int dr)

{

    if(st==dr)

    {

        arb[nod]=1;

        return;

    }

    int mijl=(st+dr)/2;

    if(poz<=mijl)

        upDate(2*nod,st,mijl);

    else

        upDate(2*nod+1,mijl+1,dr);

    arb[nod]=arb[2*nod]+arb[2*nod+1];

}

void query(int nod, int st, int dr)

{

    if(st>=pozst&&dr<=pozdr)

    {

        sum+=arb[nod];

        return;

    }

    int mijl=(st+dr)/2;

    if(pozst<=mijl)

        query(2*nod,st,mijl);

    if(pozdr>mijl)

        query(2*nod+1,mijl+1,dr);

}

int main()

{

    fin>>(beg+1);

    n=strlen(beg+1);

    for(i=1;i<=n;i++)

    {

        ch=beg[i]-96;

        G[ch].push_back(i);

    }

    fin>>(beg+1);

    for(i=1;i<=n;i++)

    {

        ch=beg[i]-96;

        if(viz[ch]<G[ch].size())

        {

            nr=viz[ch]++;

            sir[i]=G[ch][nr];

        }

        else

        {

            fout<<-1;

            return 0;

        }

    }

    for(i=1;i<=n;i++)

    {

        pozst=sir[i]+1;

        pozdr=n;

        if(pozst<=n)

            query(1,1,n);

        poz=sir[i];

        upDate(1,1,n);

    }

    fout<<sum;

    return 0;

}
