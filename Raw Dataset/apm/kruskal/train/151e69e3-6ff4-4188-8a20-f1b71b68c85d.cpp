#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



int n,m,grd[200005],tata[200005],muchii[2][200005],sol=0;



struct pct

{

    int x,y,z;

} v[400005];



bool cmp(pct a,pct b)

{

    return a.z<b.z;

}



int reprezentant(int nod)

{

    if(tata[nod]==0) return nod;

    else

    {

        int x=reprezentant(tata[nod]);

        tata[nod]=x;

        return x;

    }

}



void leaga(int a,int b)

{

    if(grd[a]<grd[b]){

     tata[a]=b;

    }

    if(grd[a]>grd[b]){

     tata[b]=a;

    }

    if(grd[a]==grd[b]){

     tata[a]=b;

     grd[b]++;

    }

}



int main()

{

    f>>n>>m;

    for(int i=1; i<=m; i++)

    {

        f>>v[i].x>>v[i].y>>v[i].z;

    }

    sort(v+1,v+m+1,cmp);

    int ct=0;

    for(int i=1; i<=m; i++)

    {

        int a=v[i].x,b=v[i].y,cost=v[i].z;

        int aa=reprezentant(a);

        int bb=reprezentant(b);



        if(aa!=bb){

         sol+=cost;

         muchii[0][++ct]=a;

         muchii[1][ct]=b;

         leaga(aa,bb);

        }

    }

    g<<sol<<'\n';

    g<<ct<<'\n';

    for(int i=1;i<=ct;i++) g<<muchii[0][i]<<' '<<muchii[1][i]<<'\n';

}
