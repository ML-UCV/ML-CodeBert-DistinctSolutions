#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
FILE *f=fopen("sate.in","r");
FILE *g=fopen("sate.out","w");
vector<pair<int,int> > G[30005];
int M,N;
queue<int> Q;
int dist[30005];
int X,Y;
const int LEN=10000;
char buff[LEN];
int ind=LEN-1;
int i32()
{
    int rez=0;
    while(buff[ind]<'0'||buff[ind]>'9')
    {
        if(++ind>=LEN)
        {
            ind=0;
            fread(buff,1,LEN,f);
        }
    }
    while(buff[ind]>='0'&&buff[ind]<='9')
    {
        rez=rez*10+buff[ind]-'0';
        if(++ind>=LEN)
        {
            ind=0;
            fread(buff,1,LEN,f);
        }
    }
    return rez;
}
int main()
{
    N=i32();M=i32();X=i32();Y=i32();
    for(int i=1;i<=N;i++)dist[i]=1<<30;
    for(int i=1;i<=M;i++)
    {
        int x,y,z;
        x=i32();y=i32();z=i32();
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
    fprintf(g,"%d",dist[Y]);
    fclose(f);
    fclose(g);
    return 0;
}
