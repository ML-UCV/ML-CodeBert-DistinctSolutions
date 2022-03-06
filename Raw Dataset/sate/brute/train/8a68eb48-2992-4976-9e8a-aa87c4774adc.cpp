#include<fstream>
using namespace std;
ifstream f("sate.in"); ofstream g("sate.out");
struct {int a,b,d;} v[100025];
int n,m,x,y,viz[30003];
int main()
{   f>>n>>m>>x>>y;
    for(int i=1;i<=m;i++) f>>v[i].a>>v[i].b>>v[i].d;
    viz[x]=1;
    while(!viz[y])
    {   for(int i=1;i<=m;i++)
        {   if(viz[v[i].a] && !viz[v[i].b])
                viz[v[i].b]= viz[v[i].a]+v[i].d;
            else
            if(!viz[v[i].a] && viz[v[i].b])
                viz[v[i].a]= viz[v[i].b]-v[i].d;
        }
    }
    g<<viz[y]-1; g.close(); f.close(); return 0;
}
