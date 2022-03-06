#include <fstream>
using namespace std;
ifstream f ("sate.in");
ofstream g ("sate.out");
int a,b,t[30001],x[100025],y[100025],c[100025],n,m;
int main()
{
    f>>n>>m>>a>>b;
    t[a]=1;
    for(int i=1;i<=m;++i) f>>x[i]>>y[i]>>c[i];
    while(!t[b])
    {
        for (int i=1;i<=m;++i)
        {
            if(t[x[i]]&&!t[y[i]]) t[y[i]]=t[x[i]]+c[i];
            else if(!t[x[i]]&&t[y[i]]) t[x[i]]=t[y[i]]-c[i];
        }
    }
    g<<t[b]-1;
}
