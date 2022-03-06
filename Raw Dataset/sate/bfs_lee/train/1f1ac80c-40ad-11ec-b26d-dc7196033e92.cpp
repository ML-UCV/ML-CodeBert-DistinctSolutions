#include <bits/stdc++.h>
#define Nmax 30001
#define ll long long
#define DIM 70000
using namespace std;
//ifstream f("sate.in");
ofstream g("sate.out");
char buffer[DIM];
int cursor=DIM-1;
void read(int &x)
{
    x=0;
    while(!isdigit(buffer[cursor]))
        if(++cursor==DIM)
        {
            cursor=0;
            fread(buffer,1,DIM,stdin);
        }
    while(isdigit(buffer[cursor]))
    {
        x=x*10+buffer[cursor]-'0';
        if(++cursor==DIM)
        {
            cursor=0;
            fread(buffer,1,DIM,stdin);
        }
    }
}
queue <int> q;
ll d[Nmax];
int n,m,X,Y;
bitset <Nmax> inq;
list <pair <int,ll> > G[Nmax];
void BF()
{
    int x;
    list <pair <int,ll> > :: iterator it;
    fill(d+1,d+n+1,LONG_LONG_MAX);
    d[X]=0;
    q.push(X);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        inq[x]=false;
        for(it=G[x].begin();it!=G[x].end();++it)
            if(d[it->first]>d[x]+it->second)
            {
                d[it->first]=d[x]+it->second;
                if(!inq[it->first])
                {
                    inq[it->first]=true;
                    q.push({it->first});
                }
            }
    }
}
int main()
{
    freopen("sate.in","r",stdin);
    read(n);
    read(m);
    read(X);
    read(Y);
    int i,x,y,k;
    for(i=1;i<=m;i++)
    {
        read(x);
        read(y);
        read(k);
        G[x].push_back({y,k});
        G[y].push_back({x,-k});
    }
    BF();
    g<<d[Y];

    return 0;
}
