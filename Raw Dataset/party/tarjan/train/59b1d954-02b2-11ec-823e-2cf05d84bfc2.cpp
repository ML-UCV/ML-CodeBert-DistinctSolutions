#include <fstream>
using namespace std;

ifstream f ("party.in");

ofstream g ("party.out");

struct

{

    int x,y,z;

}v[1031];

int p[131];

int n,m,ok,i,X,Y,Z,nr;

int main()

{

    f>>n>>m;

    for(i=1;i<=n;++i) p[i]=1;

    for(i=1;i<=m;++i) f>>v[i].x>>v[i].y>>v[i].z;

    ok=0;

    while(!ok)

    {

        ok=1;

        for(i=1;i<=m;++i)

        {

            X=v[i].x; Y=v[i].y; Z=v[i].z;

            if(Z==0) if(p[X]==0&&p[Y]==0) {p[X]=1;p[Y]=1;ok=0;break;}

            if(Z==1) if(p[X]==0&&p[Y]!=0) {p[Y]=0;ok=0;break;}

            if(Z==2) if(p[Y]==0&&p[X]!=0) {p[X]=0;ok=0;break;}

            if(Z==3) if(p[X]==1&&p[Y]==1) {p[Y]=0;ok=0;break;}

        }

    }

    for(i=1;i<=n;i++) if(p[i]) nr++;

    g<<nr<<'\n';

    for(i=1;i<=n;++i) if(p[i]) g<<i<<'\n';

    return 0;

}
