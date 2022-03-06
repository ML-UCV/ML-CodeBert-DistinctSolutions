#include <bits/stdc++.h>




using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int arb[4*30000],v[30000 +2];

int fr[30000 +2],val[30000 +2];

int n;



void update(int st, int dr, int nod, int pos)

{

    if(st==dr)

    {

        arb[nod]=fr[pos];

    }

    else

    {

        int mij=(st+dr)/2;

        if(pos<=mij) update(st,mij,2*nod,pos);

        else update(mij+1,dr,2*nod+1,pos);



        arb[nod]=arb[nod*2]+arb[nod*2+1];

    }

}



int query(int st, int dr, int nod, int res)

{

    if(st==dr)

    {

        return st;

    }

    else

    {

        int mij=(st+dr)/2;

        if(arb[2*nod]<res) return query(mij+1, dr, 2*nod+1, res-arb[2*nod]);

        else return query(st, mij, 2*nod, res);

    }

}



int main()

{

    fin>>n;

    for(int i=1; i<=n; i++)

    {

        fin>>v[i];

        fr[i]=1;

        update(1,n,1,i);

    }

    for(int i=n; i>0; i--)

    {

        int sol=query(1,n,1,v[i]);

        fr[sol]=0;

        update(1,n,1,sol);

        val[sol]=i;

    }

    for(int i=1; i<=n; i++)

    {

        fout<<val[i]<<"\n";

    }

    return 0;

}
