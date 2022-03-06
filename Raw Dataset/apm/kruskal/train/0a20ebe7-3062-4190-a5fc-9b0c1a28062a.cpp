#include <iostream>
#include <bits/stdc++.h>
using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");





struct muchii

{

    int x,y,cost;

}v[400005];



int n,m,t[200005],rang[200005];

void citire()

{

    in>>n>>m;

    for(int i=1; i<=m; ++i)

        in>>v[i].x>>v[i].y>>v[i].cost;

    for(int i=1; i<=n; ++i)

        t[i]=i,rang[i]=1;

}

int radacina(int x)

{

    if(x==t[x]) return x;

    t[x]=radacina(t[x]);

    return t[x];

}



void unire(int x, int y)

{

    if(rang[x]>rang[y])

        t[y]=x;

    else t[x]=y;

    if(rang[x]==rang[y])

        rang[y]++;

}

bool cmp(muchii x, muchii y)

{

    return x.cost<y.cost;

}

void sortare()

{

    int ok=1;

    while(ok)

    {

        ok=0;

        for(int i=1; i<m; ++i)

            if(v[i].cost>v[i+1].cost)

            {muchii aux;

            aux=v[i];

            v[i]=v[i+1];

            v[i+1]=aux;

            ok=1;

            }

    }

}

int selectat[200005];

int verif(int x, int y)

{

    if(radacina(x)==radacina(y)) return 1;

        return 0;

}

int main()

{

   citire();

    sort(v+1,v+m+1,cmp);

    int suma=0,nr=0;

    for(int i=1; i<=m; ++i)

        if(verif(v[i].x,v[i].y)==0)

        {

            unire(radacina(v[i].x),radacina(v[i].y));

            suma+=v[i].cost;

            selectat[i]=1;

            nr++;

        }

    out<<suma<<endl<<nr<<endl;

   for(int i=1; i<=m; ++i)

    if(selectat[i]) out<<v[i].x<<" "<<v[i].y<<endl;

   return 0;

}
