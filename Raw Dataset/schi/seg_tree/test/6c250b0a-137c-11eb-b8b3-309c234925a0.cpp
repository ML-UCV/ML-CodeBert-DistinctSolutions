#include <fstream>
using namespace std;

ifstream in("schi.in");

ofstream out("schi.out");

const int N=30001;

int n,v[N], sol[N],arb[3*N],poz,ans;



 void query(int p, int st, int dr)

 {

     if(st==dr)

     {

         ans=st;

         return;

     }

     int m=(st+dr)/2;

     if(poz<=arb[2*p])query(2*p,st,m);

     else

     {

         poz-=arb[2*p];

         query(2*p+1,m+1,dr);

     }



 }



void update(int p, int st, int dr)

{

     if(st==dr)

     {

        arb[p]=0;

        return;

     }



     int m=(st+dr)/2;

     if(poz<=m) update(2*p,st,m);

     else update(2*p+1,m+1,dr);

     arb[p]=arb[2*p]+arb[2*p+1];

     }



void construieste_arb(int p, int st, int dr)

{

    if(st==dr)

    {

        arb[p]=1;

        return;

    }

    else

    {

        int m=(st+dr)/2;

        construieste_arb(2*p,st,m);

        construieste_arb(2*p+1,m+1,dr);

        arb[p]=arb[2*p]+arb[2*p+1];

    }

}

int main()

{

    in>>n;

    for(int i=1;i<=n;i++) in>>v[i];

    construieste_arb(1,1,n);



    for(int i=n;i>=1;i--)

    {

        poz=v[i];

        query(1,1,n);

        sol[ans]=i;

        poz=ans;

        update(1,1,n);

    }



    for(int i=1;i<=n;i++) out<<sol[i]<<"\n";

    return 0;

}
