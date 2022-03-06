#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

struct muchie

{

    int x,y,cost;

} a[400005];

struct muchie2

{

    int x,y;

} sol[400005];

int n,m,i,r1,r2,muchii,costmin,t[200005];



bool cmp(muchie a, muchie b)

{

    return a.cost<b.cost;

}



int tata(int x)

{

    if (x==t[x]) return x;

    else t[x]=tata(t[x]);

    return t[x];

}



int main()

{



    fin>>n>>m;

    for (i=1; i<=m; i++)

        fin>>a[i].x>>a[i].y>>a[i].cost;

    sort(a+1,a+m+1,cmp);

    for (i=1; i<=n; i++)

        t[i]=i;

    for (i=1; i<=m&&muchii<n-1; i++)

    {

        r1=tata(a[i].x);

        r2=tata(a[i].y);

        if (r1!=r2)

        {

            muchii++;

            sol[muchii].x=a[i].x;

            sol[muchii].y=a[i].y;

            costmin=costmin+a[i].cost;

            t[r2]=r1;

        }

    }

    fout<<costmin<<"\n"<<n-1<<"\n";

    for (i=1; i<=muchii; i++)

        fout<<sol[i].x<<" "<<sol[i].y<<"\n";

    return 0;

}
