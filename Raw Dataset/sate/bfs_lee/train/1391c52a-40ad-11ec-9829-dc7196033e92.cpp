#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,x,y,a,b,c,X,Y;
vector <int> v[30010];
vector <int> d[30010];
bool viz[30010];
int dis[30010];
//ifstream in("sate.in");
//ofstream out("sate.out");
#define DIM 10000
char buff[DIM];
int poz=0;

void citeste(int &numar)
{
    numar=0;
    while (buff[poz]<'0' || buff[poz]>'9')
        if(++poz== DIM)
            fread(buff,1,DIM,stdin),poz=0;
    while ('0'<=buff[poz] && buff[poz]<='9')
    {
        numar=numar*10+buff[poz]-'0';
        if (++poz == DIM)
            fread(buff,1,DIM,stdin),poz=0;
    }
}

int main()
{
    freopen("sate.in","r",stdin);
    freopen("sate.out","w",stdout);

    citeste(n);
    citeste(m);
    citeste(x);
    citeste(y);
    for(i=1;i<=m;i++)
    {
        citeste(a);
        citeste(b);
        citeste(c);
        v[a].push_back(b);
        v[b].push_back(a);
        d[a].push_back(c);
        d[b].push_back(c);
    }
    X=min(x,y);
    Y=max(y,x);
    dis[X]=0;
    queue <int> q;
    q.push(X);
    viz[X]=1;
    while(!dis[Y])
    {
        int curr=q.front();
        q.pop();
        for(int i=0;i<v[curr].size() && !dis[Y];i++)
            if(!viz[v[curr][i]])
                {
                    viz[v[curr][i]]=1;
                    q.push(v[curr][i]);
                    if (v[curr][i]<curr) dis[v[curr][i]]=dis[curr]-d[curr][i];
                    else dis[v[curr][i]]=dis[curr]+d[curr][i];
                }
    }
    cout<<dis[Y];
    return 0;
}
