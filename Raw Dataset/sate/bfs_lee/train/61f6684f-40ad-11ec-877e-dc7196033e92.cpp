#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
vector < pair<int,int> > g[30010];
int ans[30010],viz[30010];
queue <int> q;
int main()
{
    ifstream fin ("sate.in");
    ofstream fout ("sate.out");
    int n,m,x,y,a,b,c,i,nod;
    fin>>n>>m>>x>>y;
    for(i=1; i<=m; i++)
    {
        fin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }
    ans[x]=0;
    q.push(x);
    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        for(i=0; i<g[nod].size(); i++)
        {
            if(viz[g[nod][i].first]==0)
            {
                viz[g[nod][i].first]=1;
                if(g[nod][i].first>nod)
                    ans[g[nod][i].first]=ans[nod]+g[nod][i].second;
                else
                    ans[g[nod][i].first]=ans[nod]-g[nod][i].second;
                q.push(g[nod][i].first);
            }
        }
    }
    fout<<ans[y];
    return 0;
}
