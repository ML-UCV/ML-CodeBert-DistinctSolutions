#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

int n,m,a[400004],s,m1;

struct graf

{

    int x,y,c;

};

bool cmp(graf x, graf y)

{

    if(x.c!=y.c)

        return x.c<y.c;

    if(x.x!=y.x)

        return x.x<y.x;

    if(x.y!=y.y)

        return x.y<y.y;

}

graf v[400004],v1[400004];

int arad(int x)

{

    while(a[x]!=0)

        x=a[x];

    return x;

}

int main()

{

    fin>>n>>m;

    for(int i=1;i<=m;i++)

        fin>>v[i].x>>v[i].y>>v[i].c;

    sort(v+1,v+m+1,cmp);

    for(int i=1;i<=m;i++)

    {

        int x=v[i].x;

        int y=v[i].y;

        int rx=arad(x);

        int ry=arad(y);

        if(rx==ry)

            continue;

        s+=v[i].c;

        if(rx<ry)

        {

            a[ry]=rx;

            v1[++m1].x=x;

            v1[m1].y=y;

        }

        else

        {

            a[rx]=ry;

            v1[++m1].x=x;

            v1[m1].y=y;

        }

    }

    fout<<s<<"\n"<<m1<<"\n";

    for(int i=1;i<=m1;i++)

        fout<<v1[i].y<<" "<<v1[i].x<<"\n";

    return 0;

}
