#include<fstream>
#include<vector>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
int n,m,S,F,p,u,x,y,cost;
int c[900010],dist[30010],v[30010];
vector < pair<int,int> > L[30010];
int main(){
    fin>>n>>m>>S>>F;
    for(int i=1;i<=m;i++){
        fin>>x>>y>>cost;
        L[x].push_back(pair<int,int>(y,cost));
        L[y].push_back(pair<int,int>(x,cost));
    }
    c[1]=S;
    p=u=1;
    v[S]=1;
    while(p<=u){
        if(c[p]==F)
            break;
        for(int i=0;i<L[c[p]].size();i++){
            if(v[L[c[p]][i].first]==0){
                v[L[c[p]][i].first]=1;
                if(c[p]<L[c[p]][i].first)
                    dist[L[c[p]][i].first]=dist[c[p]]+L[c[p]][i].second;
                else
                    dist[L[c[p]][i].first]=dist[c[p]]-L[c[p]][i].second;
                c[++u]=L[c[p]][i].first;
            }
        }
        p++;
    }
    fout<<dist[F];
    return 0;
}
