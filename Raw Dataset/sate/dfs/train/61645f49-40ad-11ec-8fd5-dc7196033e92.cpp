#include <fstream>
#include <vector>
#define f first
#define s second
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");

int viz[30010];
vector<pair <int, int> > A[30010];
int n,m,a,b,x,y,start,cost;

void DFS(int nod){
    for(int i=0; i<A[nod].size(); i++){
        int nod2=A[nod][i].f;
       int cost=A[nod][i].s;
        if(!viz[nod2]){
         viz[nod2]=viz[nod]+cost;
        DFS(nod2);
        }
    }
}

int main()
{
    fin>>n>>m>>x>>y;
    if(x>y) swap(x,y);
     for(int i=1; i<=m; i++){
        fin>>a>>b>>cost;
        A[a].push_back(make_pair(b,cost));
        A[b].push_back(make_pair(a,-cost));
    }

    DFS(x);
    fout<<viz[y]<<'\n';

    return 0;
}
