#include <fstream>
#include <vector>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

const int nmax=100000;

struct str{
    int z,k;
};

vector <str> g[nmax+1];

bool u[nmax+1];

int d[nmax+1];

int x1,y1;

void dfs(int x){
    u[x]=1;
    if(x==y1){
        return;
    }
    for(int i=0;i<int(g[x].size());i++){
        int xn=g[x][i].z;
        if(x<xn&&u[xn]==0){
            d[xn]=d[x]+g[x][i].k;
        }else if(x>xn&&u[xn]==0){
            d[xn]=d[x]-g[x][i].k;
        }
        if(u[xn]==0){
            dfs(xn);
        }
    }
}

int main(){
    int n,m;
    fin>>n>>m>>x1>>y1;
    for(int i=1;i<=m;i++){
        int x,y,k;
        fin>>x>>y>>k;
        g[x].push_back({y,k});
        g[y].push_back({x,k});
    }
    dfs(x1);
    fout<<d[y1]<<"\n";
    return 0;
}
