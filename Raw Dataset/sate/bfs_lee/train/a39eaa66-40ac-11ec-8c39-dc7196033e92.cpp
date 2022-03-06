#include <fstream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");
vector<vector<pair<int,int>>>adj;
vector<int>dist;
queue<int>q;
void bfs(int u)
{
    dist[u]=0;
    q.push(u);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(pair<int,int> j:adj[p])
        {
            if(dist[j.first]==INT_MIN)
            {
                if(j.first<p)
                    dist[j.first]=dist[p]-j.second;
                else
                    dist[j.first]=dist[p]+j.second;
                q.push(j.first);
            }
        }
    }
}
int main() {
    int n,m,x,y,a,b,d;
    in>>n>>m>>x>>y;
    adj.resize(n+1);
    dist.resize(n+1);
    for(int i=1;i<=m;i++)
    {
        in>>a>>b>>d;
        adj[a].push_back(make_pair(b,d));
        adj[b].push_back(make_pair(a,d));
    }
    for(int i=1;i<=n;i++)
    {
        dist[i]=INT_MIN;
    }
    bfs(x);
    out<<dist[y];
    return 0;
}
