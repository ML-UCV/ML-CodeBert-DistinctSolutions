#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;



ifstream fin ("apm.in");

ofstream fout ("apm.out");



struct muchie

{

    int a, b, c;

}v[400001];



int comparare (muchie x, muchie y)

{

    return x.c<y.c;

}



int tt[200001], rg[200001], afis[200000];



int find(int x)

{

    int r, y;



    r=x;

    while(tt[r]!=r)

    {

        r=tt[r];

    }





    while(tt[x]!=x)

    {

        y=tt[x];

        tt[x]=r;

        x=y;

    }



    return r;

}



void unite (int x, int y)

{

    if(rg[y]<rg[x])

    {

        tt[y]=x;

    }



    else tt[x]=y;



    if(rg[x]==rg[y]) rg[y]++;

}





int main()

{

    int n, m, i, ct, k, aux1, aux2;

    fin>>n>>m;



    for(i=1; i<=m; i++)

    {

        fin>>v[i].a>>v[i].b>>v[i].c;

    }



    sort(v+1, v+m+1, comparare);



    for(i=1; i<=n; i++)

    {

        tt[i]=i;

        rg[i]=1;

    }



    ct=0;

    k=0;

    i=1;

    while(k<n-1)

    {

        aux1=find(v[i].a);

        aux2=find(v[i].b);



        if(aux1 != aux2 )

        {

            ct=ct+v[i].c;

            k++;

            afis[k]=i;



            unite(aux1, aux2);

        }



        i++;

    }



    fout<<ct<<"\n"<<n-1<<"\n";



    for(i=1; i<n; i++)

    {

        fout<<v[ afis[i] ].b<<' '<<v[ afis[i] ].a<<"\n";

    }



}
