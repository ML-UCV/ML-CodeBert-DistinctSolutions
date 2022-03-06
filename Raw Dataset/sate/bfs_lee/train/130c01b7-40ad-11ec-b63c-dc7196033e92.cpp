#include <cstdio>
#include <queue>
using namespace std;
const int maxn=30001;
const int maxm=100025;
queue <int> q;
bool viz[maxn];
int d[maxn],cap[maxn],nxt[2*maxm],nr;
struct muchie
{
    int nod,cost;
}val[2*maxm];
inline void add(int a,int b,int c)
{
    val[++nr].nod=b;val[nr].cost=c;
    nxt[nr]=cap[a];
    cap[a]=nr;
}
inline void bfs(int x,int y)
{
    int a,b,c,p;
    q.push(x);viz[x]=true;
    while(!viz[y])
    {
        a=q.front();q.pop();
        p=cap[a];
        while(p)
        {
            b=val[p].nod;c=val[p].cost;
            if(!viz[b])
            {
                viz[b]=true;
                d[b]=d[a]+c;
                q.push(b);
            }
            p=nxt[p];
        }
    }
}
int main()
{
    FILE *fin,*fout;
    fin=fopen("sate.in","r");
    fout=fopen("sate.out","w");
    int n,m,x,y,a,b,c;
    fscanf(fin,"%d%d%d%d",&n,&m,&x,&y);
    for(int i=0;i<m;i++)
    {
        fscanf(fin,"%d%d%d",&a,&b,&c);
        add(a,b,c);add(b,a,-c);
    }
    bfs(x,y);
    fprintf(fout,"%d",d[y]);
    fclose(fin);
    fclose(fout);
    return 0;
}
