#include <fstream>
#include <algorithm>


using namespace std;



ifstream in ("apm.in");

ofstream out ("apm.out");



struct ura{

    int x,y,c,ok;

};

ura v[400005];

bool cmp(ura a,ura b)

{

    return a.c<b.c;

}

int d[200005];

int nr,cost;

int stramos(int x)

{

    if (d[x]==x)

        return x;

    int r=stramos(d[x]);

    d[x]=r;

    return r;

}

int unire(int i)

{

    int x=v[i].x,y=v[i].y;

    int d1=stramos(x),d2=stramos(y);

    d[d1]=d2;

}

int main()

{

    int n,m,i;

    in>>n>>m;

    for (i=1;i<=m;i++)

        in>>v[i].x>>v[i].y>>v[i].c;

    for (i=1;i<=n;i++)

        d[i]=i;

    sort(v+1,v+m+1,cmp);

    nr=cost=0;

    for(i=1;i<=m;i++)

        if(stramos(v[i].x)!=stramos(v[i].y)){

            unire(i);

            cost+=v[i].c;

            v[i].ok=1;

            nr++;

        }

    out<<cost<<'\n'<<nr;

    for(i=1;i<=m;i++)

        if(v[i].ok==1)

            out<<'\n'<<v[i].y<<" "<<v[i].x;

    return 0;

}
