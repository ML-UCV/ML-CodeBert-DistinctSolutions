#include <bits/stdc++.h>
using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int bit[30003], n;



int lsb(int x)

{

    return x&(-x);

}



void upd(int i, int d)

{

    for(;i<=n;i+=lsb(i)) bit[i]+=d;

}



int query(int i)

{

    int sol=0;

    for(;i;i-=lsb(i)) sol+=bit[i];

    return sol;

}



int v[30003], sol[30003];



int main()

{

    fin>>n;

    for(int i=1;i<=n;++i)

    {

        upd(i, 1);

        fin>>v[i];

    }

    for(int i=n;i;--i)

    {

        int st=1, dr=n, last=n;

        while(st<=dr)

        {

            int mij=(st+dr)/2;

            if(query(mij)>=v[i]) last=mij, dr=mij-1;

            else st=mij+1;

        }

        upd(last, -1);

        sol[last]=i;

    }

    for(int i=1;i<=n;++i) fout<<sol[i]<<"\n";

    return 0;

}
