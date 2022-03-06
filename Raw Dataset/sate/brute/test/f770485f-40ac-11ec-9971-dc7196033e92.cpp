#include<fstream>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
int n,m,x,i,y,d[30003],a[100025],b[100025],ld[100025];
int main()
{
    f>>n>>m>>x>>y;
    d[x]=1;
    for(i=1;i<=m;i++)
      f>>a[i]>>b[i]>>ld[i];
    while(d[y]==0)
        {
            for(i=1; i<=m; i++ )
            {
                if(d[a[i]]!=0&&d[b[i]]==0)
                d[b[i]]=d[a[i]]+ld[i];
                else if(d[a[i]]==0&&d[b[i]]!=0)
                d[a[i]]=d[b[i]]-ld[i];
            }
        }
    g<<d[y]-1<<'\n';
    return 0;
}
