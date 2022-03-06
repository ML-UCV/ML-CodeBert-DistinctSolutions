#include <fstream>
#define DIM 100025
using namespace std;
int sol[30001],st[DIM],dr[DIM],x[DIM];
int main()
{ int n,i,a,b,m;
    ifstream f("sate.in");
    ofstream g("sate.out");
    f>>n>>m>>a>>b;
    sol[a]=1;
    for (i=1;i<=m;++i)
        f>>st[i]>>dr[i]>>x[i];
    while (!sol[b]) {
      for (i=1;i<=m;++i)
        if (sol[st[i]] && !sol[dr[i]]) sol[dr[i]]=sol[st[i]]+x[i];
        else if (!sol[st[i]] && sol[dr[i]]) sol[st[i]]=sol[dr[i]]-x[i];
    }
    g<<sol[b]-1;
    return 0;
}
