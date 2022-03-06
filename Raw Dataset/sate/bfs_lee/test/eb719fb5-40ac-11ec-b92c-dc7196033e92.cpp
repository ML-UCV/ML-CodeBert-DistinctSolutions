#include <bits/stdc++.h>
#define Max 30003
using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");

vector<pair<int, int> >lista[Max];
queue<int>q;
int n,m,x,y,d[Max],viz[Max];

void citire()
{
    in>>n>>m>>x>>y;
    int a,b,c;
    for(int i=1;i<=m;i++)
    {
        in>>a>>b>>c;
        lista[a].push_back({b,c});
        lista[b].push_back({a,c});
    }
}
void bfs(int node)
{
    q.push(node);
    viz[node]=1;
    while(!q.empty())
    {
        int nod=q.front();
        q.pop();
        for(auto x:lista[nod])
        {
            if(!viz[x.first])
            {
                q.push(x.first);
                viz[x.first]=1;
                if(nod>x.first)
                    d[x.first]=d[nod]-x.second;
                else
                    d[x.first]=d[nod]+x.second;
                if(x.first==y)
                    return;
            }
        }
    }
}
int main()
{
    citire();
    bfs(x);
    out<<d[y];
    return 0;
}
