#include <bits/stdc++.h>


using namespace std;



const int nmax=3e4+5;

int n,v[nmax],arb[4*nmax],rasp[nmax];



void build(int nod, int st, int dr)

{

    if(st==dr)

    {

        arb[nod] = 1;

        return;

    }

    int mijl=(st+dr)/2;

    build(nod*2,st,mijl);

    build(nod*2+1,mijl+1,dr);

    arb[nod]=arb[nod*2]+arb[nod*2+1];

}

void update(int nod,int st,int dr,int x)

{

    if (st==dr)

    {

        arb[nod]=0;

        return;

    }

    int mijl=(st+dr)/2;

    if (mijl>=x)

        update(nod*2,st,mijl,x);

    else

        update(nod*2+1,mijl+1,dr,x);

    arb[nod]=arb[nod*2]+arb[nod*2+1] ;

}

int query(int nod,int st,int dr,int val)

{

    if(st==dr)

        return st;

    int mijl=(st+dr)/2;

    if (arb[nod*2]<val)

        return query(2*nod+1,mijl+1,dr,val-arb[2*nod]);

    else

        return query(2*nod,st,mijl,val);

}

int main()

{

    ifstream cin("schi.in");

    ofstream cout("schi.out");

    int poz;

    cin>>n;

    for(int i=1;i<=n;i++)

        cin>>v[i];

    build(1,1,n);

    for(int i=n;i>0;i--)

    {

        poz=query(1,1,n,v[i]);

        rasp[poz]=i;

        update(1,1,n,poz);

    }

    for (int i=1;i<=n;i++)

        cout<<rasp[i]<<"\n";

    return 0;

}
