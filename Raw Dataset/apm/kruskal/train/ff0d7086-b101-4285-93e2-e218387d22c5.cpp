#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin ("apm.in");

ofstream fout ("apm.out");

struct ura

{

    int x,y,c;

};

ura v[400001];

int sef[200001],sol[400001];

bool cmp (ura x,ura y)

{

    if (x.c<y.c)

        return true;

    else

        if (x.c>y.c)

            return false;

        else

            if (x.x<y.x)

                return true;

            else

                if (x.x>y.x)

                    return false;

                else

                    if (x.y<y.y)

                        return true;

                    else

                        return false;

}

int sefsuprem (int x)

{

    if (sef[x]==x)

        return x;

    return sef[x]=sefsuprem(sef[x]);

}

void unire (int x,int y)

{

    sef[x]=sefsuprem(x);

    sef[y]=sefsuprem(y);

    sef[sef[x]]=sef[y];

}

int main ()

{

    int n,m,i,nr=0,sum=0;

    fin>>n>>m;

    for (i=1;i<=n;i++)

        sef[i]=i;

    for (i=1;i<=m;i++)

        fin>>v[i].x>>v[i].y>>v[i].c;

    sort(v+1,v+m+1,cmp);

    for (i=1;i<=m;i++)

    {

        sef[v[i].x]=sefsuprem(v[i].x);

        sef[v[i].y]=sefsuprem(v[i].y);

        if (sef[v[i].x]!=sef[v[i].y])

        {

            nr++;

            sum+=v[i].c;

            sol[nr]=i;

            unire(v[i].x,v[i].y);

        }

    }

    fout<<sum<<'\n';

    fout<<nr<<'\n';

    for (i=1;i<=nr;i++)

        fout<<v[sol[i]].x<<" "<<v[sol[i]].y<<'\n';

    return 0;

}
