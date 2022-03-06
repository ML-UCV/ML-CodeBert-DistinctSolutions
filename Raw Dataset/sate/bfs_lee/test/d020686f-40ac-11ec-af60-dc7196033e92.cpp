#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

queue <int> q;
int vis[100005];
int dist[100005];
vector <pair<int,int>> mu[100005];
int n,m,s,a,b,f,c;

ifstream in("sate.in");
ofstream out("sate.out");


void bfs(int start){
    q.push(start);
    vis[start]=1;
    dist[start]=0;
    while(!q.empty()){
        int nod=q.front();
        for(int i=0;i<mu[nod].size();i++)
            if(vis[mu[nod][i].first]==0)
                {
                    q.push(mu[nod][i].first);
                    dist[mu[nod][i].first]=dist[nod]+mu[nod][i].second;
                    vis[mu[nod][i].first]=1;
                }
            q.pop();
    }
}

int main()
{
    in>>n>>m>>s>>f;
    for(int i=1;i<=m;i++){
        in>>a>>b>>c;
        if(a<b){
            mu[a].push_back({b,c});
            mu[b].push_back({a,-c});
        }
        else
        {
            mu[a].push_back({b,-c});
            mu[b].push_back({a,c});
        }
    }
    bfs(s);
    out<<dist[f]<<" ";

    return 0;
}
