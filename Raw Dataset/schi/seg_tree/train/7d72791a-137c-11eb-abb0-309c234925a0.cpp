#include<bits/stdc++.h>
using namespace std;



ifstream f("schi.in");

ofstream g("schi.out");



int Arb[30001*4+250],n,sol[30001],v[30001];



void fa(int node,int st,int dr)

{

    if(st==dr)

    {

        Arb[node]=1;

        return;

    }

    int mij=(dr+st)/2;

    fa(node*2,st,mij);

    fa(node*2+1,mij+1,dr);

    Arb[node]=Arb[node*2]+Arb[node*2+1];

}



int Cauta(int node,int st,int dr,int loc)

{

    if(st==dr)

    {

        return dr;

    }

    int mij=(dr+st)/2;

    if(Arb[node*2]>=loc)

    {

        return Cauta(node*2,st,mij,loc);

    }

    else

    {

        return Cauta(node*2+1,mij+1,dr,loc-Arb[2*node]);

    }

}

void Up(int node,int st,int dr,int loc)

{

    if(dr==st)

    {

        Arb[node]=0;

        return ;

    }

    int mij=(st+dr)/2;

    if(loc<=mij)

    Up(node*2,st,mij,loc);

    else

        Up(node*2+1,mij+1,dr,loc);

    Arb[node]=Arb[node*2]+Arb[node*2+1];

}



int main()

{

    f>>n;

    for(int i=1;i<=n;++i)

        f>>v[i];

    fa(1,1,n);



    for(int i=n;i>=1;--i)

    {

        int vi=Cauta(1,1,n,v[i]);

        sol[vi]=i;

        Up(1,1,n,vi);

    }

    for(int i=1;i<=n;++i)

        g<<sol[i]<<'\n';

}
