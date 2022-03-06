#include<fstream>
#include<cstdlib>
using namespace std;

ifstream f("party.in");

ofstream g("party.out");

int n,m,i,ok,nr,r,s[101];

struct muchie{int x,y,c;};

muchie v[1001];

int egresit(muchie a)

{

    if(a.c==0&&s[a.x]==0&&s[a.y]==0)

    return 1;

    if(a.c==1&&s[a.x]==0&&s[a.y]==1)

    return 1;

    if(a.c==2&&s[a.x]==1&&s[a.y]==0)

    return 1;

    if(a.c==3&&s[a.x]==1&&s[a.y]==1)

    return 1;

    return 0;

}

int main()

{

    f>>n>>m;

    for(i=1;i<=m;++i)

    f>>v[i].x>>v[i].y>>v[i].c;

    do

    {

        ok=1;

        for(i=1;i<=m;++i)

        if(egresit(v[i]))

        {

            r=rand()%2;

            if(r==0)

            {

                nr-=s[v[i].x];

                s[v[i].x]=1-s[v[i].x];

                nr+=s[v[i].x];

            }

            else

            {

                nr-=s[v[i].y];

                s[v[i].y]=1-s[v[i].y];

                nr+=s[v[i].y];

            }

            ok=0;

            break;

        }

        if(nr==0&&ok==1)

        {

            r=rand()%n+1;

            ++nr;

            s[r]=1;

            ok=0;

        }

    }while(!ok);

    g<<nr<<'\n';

    for(i=1;i<=n;++i)

    if(s[i])

    g<<i<<'\n';

    return 0;

}
