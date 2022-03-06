#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");



const int nlim=200005;

int n,m,tt[nlim],rg[nlim],total=0,z=0;

pair <int, int> P[nlim];



struct muchie

{

    int a,b,cost;

}v[nlim];



int comp(muchie a, muchie b)

{

    return a.cost<b.cost;

}



int tatal(int x)

{

    while(tt[x]!=0)

        x=tt[x];

    return x;

}



void unire(int x, int y)

{

    if(rg[x]<rg[y])

        tt[x]=y;

    if(rg[x]>rg[y])

        tt[y]=x;

    if(rg[x]==rg[y])

    {

        tt[x]=y;

        rg[y]++;

    }

}



void kruskal()

{

    for(int i=1;i<=m;i++)

    {

        int tatal_x=tatal(v[i].a);

        int tatal_y=tatal(v[i].b);

        int costul=v[i].cost;

        if(tatal_x!=tatal_y)

        {

            unire(tatal_x,tatal_y);

            total=total+costul;

            z++;

            P[z].first=v[i].a;

            P[z].second=v[i].b;

        }

    }

}



void citire()

{

    f>>n>>m;

    for(int i=1;i<=m;i++)

        f>>v[i].a>>v[i].b>>v[i].cost;

    sort(v+1,v+m+1,comp);

}



int main()

{

    citire();

    kruskal();

    g<<total<<'\n'<<z<<'\n';

    for(int i=1;i<=z;i++)

        g<<P[i].first<<" "<<P[i].second<<'\n';

    return 0;

}
