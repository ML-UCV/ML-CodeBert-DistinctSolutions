#include <iostream>
#include <cstdio>
using namespace std;

int aint[120001];

int v[30001];

int poz[30001],ok;

void goup(int nod)

{

    aint[nod]++;

    if(nod==1)

        return;

    goup(nod/2);

}

void cauta(int nod,int st,int dr,int i)

{

    if(ok==1)

        return;

    if(st==dr)

    {

        goup(nod);

        poz[st]=i;

        ok=1;

        return;

    }

    int mij=(st+dr)/2;

    if(mij-st+1-aint[2*nod]>=v[i])

        cauta(2*nod,st,mij,i);

    else

        v[i]-=(mij-st+1-aint[2*nod]);

    if(dr-mij-aint[2*nod+1]>=v[i])

        cauta(2*nod+1,mij+1,dr,i);

    else

        v[i]-=(dr-mij-aint[2*nod+1]);

}

int main()

{

    freopen("schi.in","r",stdin);

    freopen("schi.out","w",stdout);

    int n,i;

    cin>>n;

    for(i=1; i<=n; i++)

        cin>>v[i];

    for(i=n; i>=1; i--)

        {ok=0;cauta(1,1,n,i);}

    for(i=1; i<=n; i++)

        cout<<poz[i]<<'\n';

    return 0;

}
