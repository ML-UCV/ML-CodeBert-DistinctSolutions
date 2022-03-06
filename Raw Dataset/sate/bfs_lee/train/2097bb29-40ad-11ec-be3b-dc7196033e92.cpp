#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

ifstream in ("sate.in");
ofstream out ("sate.out");

vector<pair<int,int> >graf[30001];
int dist[30001];
queue<int> q;
int n,m,x,Y;

void bfs()
{
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(auto y:graf[a])
        {
            if(dist[y.first]==INF)
            {
                if(y.first<a)
                    dist[y.first]=dist[a]-y.second;
                else if(y.first>a)
                    dist[y.first]=dist[a]+y.second;
                if (y.first==Y) return;
                q.push(y.first);
            }
        }
    }
}
int abs(int k)
{
    if (k>=0) return k;
    return k*(-1);
}
int main()
{
    int i,a,b,c;
    in>>n>>m>>x>>Y;
    for(i=1;i<=m;i++)
    {
        in>>a>>b>>c;
        graf[a].push_back(make_pair(b,c));
        graf[b].push_back(make_pair(a,c));
    }
    for(i=1;i<=n;i++)
      dist[i]=INF;
    dist[x]=0;
    q.push(x);
    bfs();
    out<<abs(dist[Y]);
}
