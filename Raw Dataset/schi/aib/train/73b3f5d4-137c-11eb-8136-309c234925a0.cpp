#include <bits/stdc++.h>


using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

int n,i,v[30010],sol[30010],A[30010],poz;

void update(int poz,int val) {

    for (;poz<=n;poz+=(poz&-poz))

        A[poz]+=val;

}

int query(int poz) {

    int val=0;

    for (;poz;poz-=(poz&-poz))

        val+=A[poz];

    return val;

}

int cb(int val) {

    int st=1,dr=n,sol=n+1;

    while (st<=dr) {

        int mid=(st+dr)/2;

        if (val<=query(mid))

            dr=mid-1;

        else

            st=mid+1;

    }

    return st;

}

int main() {

    fin>>n;

    for (i=1;i<=n;i++) {

        fin>>v[i];

        update(i,1);

    }

    for (i=n;i>=1;i--) {

        poz=cb(v[i]);

        sol[poz]=i;

        update(poz,-1);

    }

    for (i=1;i<=n;i++)

        fout<<sol[i]<<"\n";

    return 0;

}
