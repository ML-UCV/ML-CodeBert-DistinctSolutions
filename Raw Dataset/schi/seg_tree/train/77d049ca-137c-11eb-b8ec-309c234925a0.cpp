#include <bits/stdc++.h>
using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int t[1000000];



int n, m, sol[30002], v[30002];



void build(int tp, int tl, int tr)

{

    if(tl==tr) t[tp]=1;

    else

    {

        int m=(tl+tr)/2;

        build(tp*2, tl, m);

        build(tp*2+1, m+1, tr);

        t[tp]=t[tp*2]+t[tp*2+1];

    }

}



void update(int tp, int tl, int tr, int poz)

{

    t[tp]--;

    if(tl!=tr)

    {

        int m=(tl+tr)/2;

        if(poz<=m) update(tp*2, tl, m, poz);

        else update(tp*2+1, m+1, tr, poz);

    }

}



int query(int tp, int tl, int tr, int x)

{

    if(tl==tr) return tl;

    else

    {

        int m=(tl+tr)/2;

        if(x<=t[tp*2]) return query(tp*2, tl, m, x);

        else return query(tp*2+1, m+1, tr, x-t[tp*2]);

    }

}



int main()

{

    fin>>n;

    for(int i=1;i<=n;++i) fin>>v[i];

    build(1, 1, n);

    for(int i=n;i;--i)

    {

        int place=query(1, 1, n, v[i]);

        update(1, 1, n, place);

        sol[place]=i;

    }

    for(int i=1;i<=n;++i) fout<<sol[i]<<"\n";

    return 0;

}
