#include<fstream>




using namespace std;

ifstream f("party.in"); ofstream g("party.out");

struct art {int x,y,z;} a[1001];

int nr,p[101];

int main()

{ int n,m,i;

    f>>n>>m;

    for(i=1;i<=n;++i) p[i]=1;

    for(i=1;i<=m;i++) f>>a[i].x>>a[i].y>>a[i].z;

    int x,y,z,ok=0;

    while(ok==0)

    { ok=1;

        for(i=1;i<=m;i++)

        { x=a[i].x; y=a[i].y; z=a[i].z;

            if(z==0 && p[x]==0 && p[y]==0) {p[x]=1; p[y]=1; ok=0; break;}

            if(z==1 && p[x]==0 && p[y]!=0) {p[y]=0; ok=0; break;}

            if(z==2 && p[y]==0 && p[x]!=0) {p[x]=0; ok=0; break;}

            if(z==3 && p[x]==1 && p[y]==1) {p[y]=0; ok=0; break;}

        }

    }

    for(i=1;i<=n;i++) if(p[i]) nr++;

    g<<nr<<'\n';

    for(i=1;i<=n;i++) if(p[i]) g<<i<<'\n';

    g.close(); return 0;

}
