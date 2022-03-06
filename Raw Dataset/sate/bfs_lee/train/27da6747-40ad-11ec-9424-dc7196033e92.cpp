#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
vector<pair<int,int> > G[30005];
int M,N;
queue<int> Q;
int dist[30005];
int X,Y;
int main()
{
    freopen("sate.in","r",stdin);
    freopen("sate.out","w",stdout);
    cin.sync_with_stdio(false);cin.tie(0);
    cout.sync_with_stdio(false);cout.tie(0);
    cin>>N>>M>>X>>Y;
    for(int i=1;i<=N;i++)dist[i]=1<<30;
    for(int i=1;i<=M;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        G[x].push_back({y,z});
        G[y].push_back({x,-z});
    }
    dist[X]=0;
    Q.push(X);
    while(!Q.empty())
    {
        int nod=Q.front();Q.pop();
        for(auto it:G[nod])
            if(dist[it.first]>dist[nod]+it.second)
            {dist[it.first]=dist[nod]+it.second;Q.push(it.first);}
    }
    cout<<dist[Y];
    return 0;
}
