#include<iostream>
#include<fstream>
#include<vector>
#define DN 30050
using namespace std;

fstream fin("sate.in",ios::in),fout("sate.out",ios::out);
vector< pair<int,int> > v[DN];
int N,M,X,Y,ok=0;
int dist[DN];


void dfs(int nod)
{
    if(nod==Y)
    {
        fout<<(dist[nod]-1)<<"\n";
        ok=1;
    }
    if(ok==1) return ;
    for(auto i:v[nod])
    {
        if(dist[i.first]==0)
        {
            dist[i.first]=dist[nod]+i.second;
            dfs(i.first);
        }
    }
}
int main()
{
    int i,j,x,y,d;
    fin>>N>>M>>X>>Y;
    for(i=1;i<=M;i++)
    {
        fin>>x>>y>>d;
        if(x<y)
        {
            v[x].push_back({y,d});
            v[y].push_back({x,-d});
        }
        else
        {
            v[y].push_back({x,d});
            v[x].push_back({y,-d});
        }
    }
    dist[X]=1;
    dfs(X);
}
