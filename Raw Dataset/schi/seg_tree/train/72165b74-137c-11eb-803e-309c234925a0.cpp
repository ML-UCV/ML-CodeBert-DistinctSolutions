#include <bits/stdc++.h>


using namespace std;



ifstream fin ("schi.in");

ofstream fout ("schi.out");



const int nmax = 3e4 + 5;



int arb[3*nmax];



int n, a[nmax], sol[nmax];



void build (int ls = 1, int ld = n, int pos = 1)

{

    if (ls == ld)

    {

        arb[pos] = 1;

        return;

    }



    int mij = (ls + ld) / 2;

    build(ls, mij, 2*pos);

    build(mij+1, ld, 2*pos+1);



    arb[pos] = arb[2*pos] + arb[2*pos+1];

}



void query (int ls, int ld, int pos, int val, int indice)

{

    if (ls == ld)

    {

        sol[ls] = indice;

        arb[pos] = 0;

        return;

    }



    int mij = (ls + ld) / 2;

    if (arb[2*pos] >= val) query(ls, mij, 2*pos, val, indice);

    else query(mij+1, ld, 2*pos+1, val - arb[2*pos], indice);



    arb[pos] = arb[2*pos] + arb[2*pos+1];

}



int main()

{

    fin >> n;

    for (int i=1; i<=n; ++i)

        fin >> a[i];



    build();



    for (int i=n; i>=1; --i)

    {

        query(1,n,1,a[i],i);

    }



    for (int i=1; i<=n; ++i)

        fout << sol[i] << '\n';

    return 0;

}
