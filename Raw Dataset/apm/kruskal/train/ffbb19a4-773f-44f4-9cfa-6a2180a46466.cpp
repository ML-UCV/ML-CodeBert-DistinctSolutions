#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

struct idk

{

    int x,y,c;

};

idk v[400004];

int v1[200004],a[200004],n,m,m1,s;

bool cmp(idk x, idk y)

{

    return x.c<y.c;

}

int arad(int x)

{

    while(a[x]>0)

        x=a[x];

    return x;

}

int main()

{

    fin>>n>>m;

    for(int i=1;i<=m;i++)

    {

        fin>>v[i].x>>v[i].y>>v[i].c;

        if(i<=n)

            a[i]=-1;

    }

    sort(v+1,v+m+1,cmp);

    for(int i=1;i<=m;i++)

    {

        int x1=arad(v[i].x);

        int y1=arad(v[i].y);

        if(x1==y1)

            continue;

        v1[++m1]=i;

        s+=v[i].c;

        if(a[x1]>a[y1])

        {

            a[y1]+=a[x1];

            a[x1]=y1;

        }

        else

        {

            a[x1]+=a[y1];

            a[y1]=x1;

        }

    }

    fout<<s<<"\n"<<m1<<"\n";

    for(int i=1;i<=m1;i++)

        fout<<v[v1[i]].y<<" "<<v[v1[i]].x<<"\n";

    return 0;

}
