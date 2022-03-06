#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int n,m,cost[100100];
bool viz[100100];
vector<pair<int,int>> edges[100100];
queue<int> q;

void BFS(int x)
{
    int i;
    q.push(x);
    viz[x] = 1;
    while(!q.empty())
    {
        int node = q.front();
        for(i=0;i<edges[node].size();i++)
            if(!viz[edges[node][i].first])
            {
                //cout<<edges[node][i].first<<" ";
                viz[edges[node][i].first] = 1;
                q.push(edges[node][i].first);
                cost[edges[node][i].first] = cost[node] + edges[node][i].second;
            }
        q.pop();

    }
}

int main()
{
    int i,x,y,z,start,stop;

    f>>n>>m>>start>>stop;
    for(i=1;i<=m;i++)
    {
        f>>x>>y>>z;

        edges[x].push_back(make_pair(y,z));
        edges[y].push_back(make_pair(x,-z));
    }

    BFS(start);

    g<<cost[stop];

    f.close();
    g.close();
    return 0;
}
