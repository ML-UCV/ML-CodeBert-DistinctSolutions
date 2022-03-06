#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n,nc,x,y,i,j,k,nr;
int f[201],ctc[201],s[201],t[201];
vector <int> v[201],inv[201];

inline int nt(int x){return (x+n)%(2*n);}
inline void add(int x,int y){v[nt(x)].push_back(y);v[nt(y)].push_back(x);inv[x].push_back(nt(y));inv[y].push_back(nt(x));}

void dfs(int x)
{
    if(f[x])
        return;
    f[x]=1;
    for(vector <int>::iterator i=v[x].begin();i!=v[x].end();++i)
        dfs(*i);
    s[++s[0]]=x;
}

void dfs2(int x,int y)
{
    if(f[x])
        return;
    f[x]=1;
    ctc[x]=y;
    for(int i=0;i<inv[x].size();++i)
        dfs2(inv[x][i],y);
}

int main()
{
    int i,nod=0,ok,m;
    freopen("party.in","r",stdin);
    freopen("party.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(;m;--m)
    {
        scanf("%d%d%d",&x,&y,&ok);
        --x;
        --y;
        if(ok&1)
            y=nt(y);
        if(ok&2)
            x=nt(x);
        add(x,y);
    }
    for(i=0;i<2*n;++i)
        if(!f[i])
            dfs(i);
    memset(f,0,sizeof(f));
    for(i=2*n;i;--i)
    {
        t[i-1]=2;
        if(!f[s[i]])
            dfs2(s[i],++nc);
    }
    for(i=2*n;i;--i)
    {
        nod=s[i];
        if(t[ctc[nod]]!=2)
            continue;
        t[ctc[nod]]=0;
        t[ctc[nt(nod)]]=1;
    }
    for(nr=0,i=0;i<n; ++i)
        nr+=t[ctc[i]];
    printf("%d\n", nr);
    for(i=0;i<n;++i)
        if(t[ctc[i]])
            printf("%d\n",i+1);
    return 0;
}
