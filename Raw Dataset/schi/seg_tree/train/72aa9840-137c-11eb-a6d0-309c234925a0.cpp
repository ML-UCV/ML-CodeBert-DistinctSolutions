#include <bits/stdc++.h>


using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

int n,i,v[30010],sol[30010],A[3*30010];

void build(int nod,int st,int dr) {

    if (st==dr)

        A[nod]=1;

    else {

        int mid=(st+dr)/2;

        build(2*nod,st,mid);

        build(2*nod+1,mid+1,dr);

        A[nod]=A[2*nod]+A[2*nod+1];

    }

}

void update(int nod,int st,int dr,int x,int poz) {

    if (st==dr) {

        A[nod]=0;

        sol[st]=x;

    }

    else {

        int mid=(st+dr)/2;

        if (A[2*nod]>=poz)

            update(2*nod,st,mid,x,poz);

        else

            update(2*nod+1,mid+1,dr,x,poz-A[2*nod]);

        A[nod]=A[2*nod]+A[2*nod+1];

    }

}

int main() {

    fin>>n;

    for (i=1;i<=n;i++)

        fin>>v[i];

    build(1,1,n);

    for (i=n;i>=1;i--)

        update(1,1,n,i,v[i]);

    for (i=1;i<=n;i++)

        fout<<sol[i]<<"\n";

    return 0;

}
