#include <fstream>
#include <vector>
#define DIM 30010
#define X first
#define Y second
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
int c[DIM],f[DIM],p,u,i,j,nod,n,m,x,y,tot,d,w[DIM];
vector< pair<int,int> >L[DIM];
int main(){
    fin>>n>>m>>x>>y;
    while(fin>>i>>j>>d){
        L[i].push_back(make_pair(j,d));
        L[j].push_back(make_pair(i,-d));
    }
    p=1; u=1; c[1]=x; f[x]=1;
    while(p<=u){
        nod=c[p];
        for(i=0;i<L[nod].size();i++)
            if(f[L[nod][i].X]==0){
                f[L[nod][i].X]=1;
                c[++u]=L[nod][i].X;
                w[L[nod][i].X]=w[nod]+L[nod][i].Y;
            }
         p++;
    }
    fout<<w[y];
    return 0;
}
