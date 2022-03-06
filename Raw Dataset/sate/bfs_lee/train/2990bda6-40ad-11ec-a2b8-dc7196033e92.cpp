#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int nmax=30005;
typedef pair<int,int> ii;
vector<ii> g[nmax];
queue<int> q;
int lng[nmax];

int main()
{
    freopen("sate.in","r",stdin);
    freopen("sate.out","w",stdout);
    int x,y,n,start,finish,cost,m,i;
    bool a=0;
    scanf("%d%d%d%d",&n,&m,&start,&finish);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&cost);
        g[x].push_back(ii(y,cost));
        g[y].push_back(ii(x,-cost));
    }
    for(i=1;i<=n;i++)
        lng[i]=-21000000;
    lng[start]=0;
    q.push(start);
    int node,sz;
    while(!q.empty())
    {
        node=q.front();
        sz=g[node].size();
        q.pop();
        for(i=0;i<sz;i++)
        {
            if(lng[g[node][i].first]==-21000000)
            {
                lng[g[node][i].first]=lng[node]+g[node][i].second;
                if(g[node][i].first==finish)
                {
                    a=1;
                    break;
                }
                q.push(g[node][i].first);
            }
        }
        if(a)
            break;
    }
    printf("%d",lng[finish]);
}
