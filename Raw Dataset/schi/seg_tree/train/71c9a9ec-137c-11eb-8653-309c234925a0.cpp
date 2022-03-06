#include <iostream>
#include <fstream>


using namespace std;



ifstream in ("schi.in");

ofstream out ("schi.out");



const int N=1<<17;

const int Nmax=30000;



int t[N],v[Nmax],sol[Nmax],nod,poz;



void actualizare (int p, int st, int dr)

{

    if (st==dr)

    {

        sol[st]=nod;

        t[p]++;

        return;

    }

    int m=(st+dr)/2;

    if (poz<=(m-st+1-t[2*p]))

    {

        actualizare (p*2,st,m);

    }

    else

    {

        poz-=(m-st+1-t[p*2]);

        actualizare (p*2+1,m+1,dr);

    }

    t[p]++;

}

int main()

{

    int n;

    in>>n;

    t[1]=1;

    for (int i=1;i<=n;i++)

        in>>v[i];



    for (int i=n;i>0;i--)

    {

        nod=i;

        poz=v[i];

        actualizare (1,1,n);

    }

    for (int i=1;i<=n;i++)

        out<<sol[i]<<'\n';

    return 0;

}
