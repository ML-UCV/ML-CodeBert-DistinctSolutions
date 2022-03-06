#include <bits/stdc++.h>




using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



int n,m;

int vf[2*100000 +1],urm[2*100000 +1],last[100000 +1],nr;

int vf2[2*100000 +1],urm2[2*100000 +1],last2[100000 +1];

int ord[100000 +1],t;

bitset <100000 +1> viz;

int vf3[100000 +1],urm3[100000 +1],last3[100000 +1],nrc;



void adauga(int nod,int vec)

{

    vf[++nr]=vec;

    urm[nr]=last[nod];

    last[nod]=nr;



    swap(nod,vec);



    vf2[nr]=vec;

    urm2[nr]=last2[nod];

    last2[nod]=nr;

}



void adaugaT(int nod,int nrc)

{

    vf3[++nr]=nod;

    urm3[nr]=last3[nrc];

    last3[nrc]=nr;

}



void dfs(int nod)

{

    viz[nod]=1;



    for(int k=last[nod];k;k=urm[k])

        if(!viz[ vf[k] ])

            dfs(vf[k]);



    ord[++t]=nod;

}



void dfst(int nod,int nrc)

{

    viz[nod]=1;

    adaugaT(nod,nrc);



    for(int k=last2[nod];k;k=urm2[k])

        if(!viz[ vf2[k] ])

            dfst(vf2[k],nrc);

}



int main()

{

    in>>n>>m;



    for(int k=1,i,j;k<=m;k++)

    {

        in>>i>>j;

        adauga(i,j);

    }



    for(int i=1;i<=n;i++)

        if(!viz[i])

            dfs(i);



    nr=0;viz=0;

    for(int i=n;i>=1;i--)

        if(!viz[ ord[i] ])

            dfst(ord[i],++nrc);



    out<<nrc<<'\n';



    for(int i=1;i<=nrc;i++)

    {

        for(int k=last3[i];k;k=urm3[k])

            out<<vf3[k]<<' ';

        out<<'\n';

    }



    return 0;

}
