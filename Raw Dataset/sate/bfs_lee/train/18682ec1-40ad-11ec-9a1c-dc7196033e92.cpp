#include <fstream>
#include <vector>
using namespace std;
ifstream fin ("sate.in");
ofstream fout ("sate.out");
vector <pair<int,int> > L[30010];
int v[30010],d[30010],c[30010],n,m,s1,s2,i,x,y,cost;

void bfs(int nod){
    v[nod]=1;
    c[1]=nod;
    int u,p;
    u=p=1;
    while(p<=u){
        int nodc=c[p];
        for(int i=0;i<L[nodc].size();i++){
            int nodv=L[nodc][i].first;
            int cost=L[nodc][i].second;
            if(v[nodv]==0){
                if(nodv>nodc)
                    d[nodv]+=d[nodc]+cost;
                else
                    d[nodv]+=d[nodc]-cost;
                if(nodv==s2)
                    return;
                v[nodv]=1;
                c[++u]=nodv;
            }
        }
        ++p;
    }
}
int main(){
    fin>>n>>m>>s1>>s2;
    for(i=1;i<=m;i++){
        fin>>x>>y>>cost;
        L[x].push_back(make_pair(y,cost));
        L[y].push_back(make_pair(x,cost));
    }
    bfs(s1);
    fout<<d[s2];
    return 0;
}
