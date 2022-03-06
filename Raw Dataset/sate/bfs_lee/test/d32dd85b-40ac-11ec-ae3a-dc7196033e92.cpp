
#include <bits/stdc++.h>
#define NMAX 30000

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int n,m,x,y,ii,jj,dd,dist[NMAX+5],viz[NMAX+5];
vector< pair<int,int> > G[NMAX+5];
queue <int> q;

void bfs(){
    q.push(x);
    while(!q.empty()){
        ii=q.front();
        q.pop();
        for(int i=0;i<G[ii].size();i++){
            jj=G[ii][i].first;
            dd=G[ii][i].second;
            if(!viz[jj]){
                viz[jj]=1;
                if(ii<jj){
                    dist[jj]=dist[ii]+dd;
                }else{
                    dist[jj]=dist[ii]-dd;
                }
                q.push(jj);
            }
        }
    }
}

int main(){
    f>>n>>m>>x>>y;
    for(int i=1;i<=m;i++){
        f>>ii>>jj>>dd;
        G[ii].push_back(make_pair(jj,dd));
        G[jj].push_back(make_pair(ii,dd));
    }
    bfs();
    g<<dist[y];
    f.close();
    g.close();
}
