#include<fstream>
#define Nmax 100025
using namespace std;
ifstream f("sate.in"); ofstream g("sate.out");
int n,m,x,y,a[Nmax],b[Nmax],d[Nmax],viz[30003];
int main()
{   f>>n>>m>>x>>y;
    for(int i=1;i<=m;i++) f>>a[i]>>b[i]>>d[i];
    viz[x]=1;
    while(!viz[y])
        for(int i=1;i<=m;i++)
            if(viz[a[i]] && !viz[b[i]]) viz[b[i]]= viz[a[i]]+d[i];
            else
            if(!viz[a[i]] && viz[b[i]]) viz[a[i]]= viz[b[i]]-d[i];
    g<<viz[y]-1; g.close(); f.close(); return 0;
}
