#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



int vt[400005],r[400005],ind[400005];

int n,m,s,k;

struct muchie

{

    int x,y,c;

}e[400005];

bool compara(muchie a, muchie b)

{

    return (a.c<b.c);

}

void citire()

{

    fin>>n>>m;

    for(int i=1; i<=m; i++)

    {

        fin>>e[i].x>>e[i].y>>e[i].c;

    }

    sort(e+1,e+m+1,compara);

}

int radacina(int x)

{

    while(vt[x]!=x)

        x=vt[x];

    return x;

}



void unire(int x, int y)

{

    if(r[x]<r[y])

        vt[x]=y;

    if(r[x]>r[y])

        vt[y]=x;

    if(r[x]==r[y])

    {

        vt[y]=x;

        r[x]++;

    }

}

void kruskal()

{

    for(int i=1;i<=n;i++)

        vt[i]=i;

    for(int i=1;i<=m;i++)

    {

        int a=radacina(e[i].x);

        int b=radacina(e[i].y);

        if(a!=b)

        {

            unire(a,b);

            s=s+e[i].c;

            k++;

            ind[k]=i;

        }

    }

}

void afisare()

{

    fout<<s<<endl<<n-1<<endl;

    for(int i=1;i<=k;i++)

    {

        fout<<e[ind[i]].x<<" "<<e[ind[i]].y<<endl;

    }

}

int main()

{

    citire();

    kruskal();

    afisare();

    return 0;

}
