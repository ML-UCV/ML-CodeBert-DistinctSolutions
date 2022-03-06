#include <bits/stdc++.h>
#define inf 10000000
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
int n,m,x,y;
vector<pair<int,int > > vecini[30005];
bool viz[30005];
int dist[30005];
queue<int> q;
int citire()
{
    char ch;
    int nr=0;
    f.get(ch);
    while(ch!=' ' and ch!='\n')
        nr=nr*10+ch-'0',f.get(ch);
    return nr;
}
int main()
{
    n=citire(),m=citire(),x=citire(),y=citire();
    for(int i=1; i<=m; i++)
    {
        int a,b,cost;
        a=citire();
        b=citire();
        cost=citire();
        vecini[a].push_back({b,cost});
        vecini[b].push_back({a,-cost});

    }
    viz[x]=1;
    q.push(x);
    while(!q.empty())
    {
        int node=q.front();
        for(int i=0; i<vecini[node].size(); i++)
        {
            int newnode=vecini[node][i].first;
            if(viz[newnode]==0)
            {
                viz[newnode]=1;
                dist[newnode]=dist[node]+vecini[node][i].second;
                q.push(newnode);
                if(newnode==y)
                {
                    g<<dist[y];
                    return 0;
                }
            }
        }
        q.pop();

    }

}
