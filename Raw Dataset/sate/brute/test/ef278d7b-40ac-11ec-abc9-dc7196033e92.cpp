#include <fstream>
#include <vector>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
vector < pair <int, int> >g[30001];
int dist[30001],q[30001];
bool viz[30001];
int n,m,x,y,a,b,d,st,dr;
int main()
{
    fin>>n>>m>>x>>y;
    for(int i=1;i<=m;i++)
    {
        fin>>a>>b>>d;
        g[a].push_back(make_pair(b,d)),
        g[b].push_back(make_pair(a,-d));
    }
    st=dr=1;
    q[1]=x;
    viz[x]=1;
    while(st<=dr)
    {
        for(int i=0;i<g[q[st]].size();i++)
        {
            if(viz[g[q[st]][i].first]==0)
            {
                viz[g[q[st]][i].first]=1;
                dist[g[q[st]][i].first]=dist[q[st]]+g[q[st]][i].second;
                q[++dr]=g[q[st]][i].first;
            }
        }
        st++;
    }
    fout<<dist[y];
    return 0;
}
