#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");

vector<pair<int,int> >v[30001];
int dist[30001];
int main()
{
    int p,r,d;
    queue<int> q;
    int n,m,x,y;
    fin>>n>>m>>x>>y;
    for(int i=1;i<=m;i++)
    {
        fin>>p>>r>>d;
        v[p].push_back({r,d});
        v[r].push_back({p,d});
    }
    dist[x]=0;
    q.push(x);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++)
        {
            if(dist[v[x][i].first]==0 && v[x][i].first!=x)
            {
                q.push(v[x][i].first);
                if(x<v[x][i].first)
                    dist[v[x][i].first]=v[x][i].second+dist[x];
                else
                    dist[v[x][i].first]=dist[x]-v[x][i].second;
            }


        }
    }
    fout<<dist[y];
    return 0;
}
