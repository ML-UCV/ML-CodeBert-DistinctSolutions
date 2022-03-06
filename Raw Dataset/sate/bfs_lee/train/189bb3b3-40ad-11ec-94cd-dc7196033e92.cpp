#include<fstream>
#include<vector>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
int n, m, A, B, dist[30002], c[30002];
bool viz[30002];
vector<pair<int, int> > l[100030];
void bfs(int nod)
{
    viz[nod]=1;
    int p=1;
    int u=1;
    c[1]=nod;
    while(p<=u)
    {
        int nodc=c[p];
        for(int i=0;i<l[nodc].size();i++)
        {
            int nodv=l[nodc][i].first;
            int cost=l[nodc][i].second;
            if(viz[l[nodc][i].first]==0)
            {
                dist[nodv]=dist[nodc];
                if(nodv<nodc)
                    dist[nodv]-=cost;
                else dist[nodv]+=cost;
                viz[l[nodc][i].first]=1;
                c[++u]=l[nodc][i].first;
            }
        }
        p++;
    }
}
int main()
{
    f>>n>>m>>A>>B;
    for(int i=1;i<=m;i++)
    {
        int x, y, c;
        f>>x>>y>>c;
        l[x].push_back(make_pair(y, c));
        l[y].push_back(make_pair(x, c));
    }
    bfs(A);
    g<<dist[B];
    return 0;
}
