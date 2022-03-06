#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f
using namespace std;
ifstream fi("sate.in");
ofstream fo("sate.out");
queue<int> q;
vector<pair<int,int> > ways[30005];
vector<int> graph[30005];
int dist[30005];
int a,b,c;
int n,m,X,Y;
int GetDistance(int a,int b)
{
    for(auto y:ways[a])
    {
        if(b== y.first)
            return y.second;
    }
}

void lee(int d)
{
    q.push(d);
    dist[d] = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto y:ways[x])
        {
            if(dist[y.first] == INF)
            {
                int k = dist[x] - GetDistance(x,y.first);
                int mk = dist[x] + GetDistance(x,y.first);
                if(x>y.first) dist[y.first] = k;
                else if(x<y.first) dist[y.first] = mk;
                q.push(y.first);
                if(y.first == Y)
                {
                    return;
                }
            }

        }
    }
}

int main()
{

    fi>>n>>m>>X>>Y;
    for(int i=1;i<=m;++i)
    {
        fi>>a>>b>>c;
        ways[a].push_back({b,c});
        ways[b].push_back({a,c});
    }
    for(int i=1;i<=n;++i)
        dist[i] = INF;
    lee(X);
    fo<<dist[Y];




}
