#include <bits/stdc++.h>


using namespace std;



ifstream in("schi.in");

ofstream out("schi.out");



const int N=1 << 17, Q=30001;



int t[N], v[Q], sol[Q];

int poz, val;



void actualizare(int p, int st, int dr)

{

    if(st==dr)

    {

        sol[st]=val;

        t[p]++;

        return;

    }

    int m=(st+dr)/2;

    if(poz<=m-st+1-t[2*p])

        actualizare(2*p, st, m);

    else

    {

        poz-=(m-st+1-t[2*p]);

        actualizare(2*p+1, m+1, dr);

    }

    t[p]++;

}



int main()

{

    int n, q;

    in>>n;

    for(int i=1; i<=n; i++)

        in>>v[i];

    t[1]=1;

    for(int i=n; i>=1; i--)

    {

        val=i;

        poz=v[i];

        actualizare(1,1,n);

    }

    for(int i=1; i<=n; i++)

        out<<sol[i]<<"\n";

    return 0;

}
