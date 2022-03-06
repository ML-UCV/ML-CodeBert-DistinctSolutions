#include <fstream>
using namespace std;

ifstream in("schi.in");

ofstream out("schi.out");

const int N=30001;

int n,v[N], sol[N],arb[3*N],poz,ans;



void interogare(int p, int st, int dr)

{

     if(st==dr)

     {

         ans=st;

         return;

     }

     int m=(st+dr)/2;

     if(poz<=arb[2*p])

        interogare(2*p,st,m);

     else

     {

         poz-=arb[2*p];

         interogare(2*p+1,m+1,dr);

     }



 }



void actualizare(int p, int st, int dr)

{

     if(st==dr)

     {

        arb[p]=0;

        return;

     }



     int m=(st+dr)/2;



     if(poz<=m)

        actualizare(2*p,st,m);

     else

        actualizare(2*p+1,m+1,dr);



     arb[p]=arb[2*p]+arb[2*p+1];

}



void constr(int p, int st, int dr)

{

    if(st==dr)

    {

        arb[p]=1;

        return;

    }

    else

    {

        int m=(st+dr)/2;

        constr(2*p,st,m);

        constr(2*p+1,m+1,dr);

        arb[p]=arb[2*p]+arb[2*p+1];

    }

}



int main()

{

    in>>n;

    for(int i=1;i<=n;i++)

        in>>v[i];

    constr(1,1,n);



    for(int i=n;i>=1;i--)

    {

        poz=v[i];

        interogare(1,1,n);

        sol[ans]=i;

        poz=ans;

        actualizare(1,1,n);

    }



    for(int i=1;i<=n;i++)

        out<<sol[i]<<"\n";

    return 0;

}
