#include <bits/stdc++.h>






using namespace std;

ifstream fin ("apm.in");

ofstream fout ("apm.out");

struct muchie

{

    int x,y,c,ok;

}v[400001];



int n,m,i,t[200001];



int tata(int x)

{

    int r, y, aux;

    r=x;

    while(t[r]!=0)

        r=t[r];



    y=x;

    while(t[y]!=0)

    {

        aux=t[y];

        t[y]=r;

        y=aux;

    }

    return r;

}



bool comp(muchie u, muchie v)

{

    if(u.c<v.c)

        return 1;

    return 0;

}



int main()

{

    fin>>n>>m;

    for(i=1;i<=m;i++)

        fin>>v[i].x>>v[i].y>>v[i].c;

    int j;

    sort(v+1, v+m+1, comp);

    for(i=1;i<=n;i++)

        t[i]=0;

   int ct=0;

   int nr=0;

   i=1;

   int x,y,tx,ty;

    while(nr<n-1)

    {

        x=v[i].x;

        y=v[i].y;

        tx=tata(x);

        ty=tata(y);

        if(tx!=ty)

        {

            nr++;

            v[i].ok=1;

            ct=ct+v[i].c;

            t[ty]=tx;

        }

        i++;

    }

    fout<<ct<<'\n'<<n-1<<'\n';

    for(i=1;i<=m;i++)

        if(v[i].ok==1)

            fout << v[i].x<<' '<<v[i].y<<'\n';

    return 0;

}
