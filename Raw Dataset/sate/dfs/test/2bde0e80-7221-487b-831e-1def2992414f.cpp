#include<stdio.h>
#include<vector>
#define MAXV 30000
#define MAXE 100024
#define MASK 32767
#define MAXBUF 100000
struct Edge
{
    int MIN,MAX,COST;
};
void read(int& n);
void dfs(int nod,int dist);
FILE*fin,*fout;
char buf[MAXBUF+1];
int pos=0;
Edge edges[MAXE+1];
bool visited[MAXE+1];
std::vector<int> neighbors[MAXV+1];
int V,E,X,Y;
int ans;
int main()
{
    fin=fopen("sate.in","r");
    fout=fopen("sate.out","w");
    read(V);
    read(E);
    read(X);
    read(Y);
    for(int i=1;i<=E;i++)
    {
        int left,right,dist;
        read(left);
        read(right);
        read(dist);
        neighbors[left].push_back(i);
        neighbors[right].push_back(i);
        edges[i].MIN=left;
        edges[i].MAX=right;
        edges[i].COST=dist;
    }
    dfs(X,0);
    fprintf(fout,"%d",ans);
    fclose(fin);
    fclose(fout);
}
void dfs(int nod,int dist)
{
    if(nod==Y)
    {
        ans=dist;
    }
    for(int i=0;i<neighbors[nod].size();i++)
    {
        int muchie=neighbors[nod][i];
        if(!visited[muchie])
        {
            visited[muchie]=1;
            if(edges[muchie].MIN==nod)
            {
                dfs(edges[muchie].MAX,dist+edges[muchie].COST);
            }
            else
            {
                dfs(edges[muchie].MIN,dist-edges[muchie].COST);
            }
        }
    }
}
void read(int& n)
{
    n=0;
    while('0' > buf[pos] || '9' < buf[pos])
    {
        pos++;
        if(pos==MAXBUF)
        {
            fread(buf,1,MAXBUF,fin);
            pos=0;
        }
    }
    while('0'<=buf[pos] && buf[pos]<='9')
    {
        n=n*10+buf[pos]-'0';
        pos++;
        if(pos==MAXBUF)
        {
            fread(buf,1,MAXBUF,fin);
            pos=0;
        }
    }
}
