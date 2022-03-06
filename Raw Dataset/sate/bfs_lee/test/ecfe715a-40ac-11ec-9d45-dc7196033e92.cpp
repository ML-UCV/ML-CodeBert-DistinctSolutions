#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
vector <pair<int,int> >G[30005];
queue <int > Q;
int n,m,a,b,l[30005];
void citire()
{
    fin>>n>>m>>a>>b;
    for(int i=1; i<=m; i++)
    {   int x,y,d;
        fin>>x>>y>>d;
        G[x].push_back({y,d});
        G[y].push_back({x,d});
    }

}
void bfs()
{
    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for(auto &v: G[x])
        {
            if(l[v.first]==0)
            {
                Q.push(v.first);
                if(v.first<x)
                l[v.first]=l[x]-v.second;
                else
                l[v.first]=l[x]+v.second;

            }
        }
    }
}
void afish()
{
    fout<<l[b];
}
int main()
{
    citire();
    if(a>b) swap(a,b);
    Q.push(a);
    bfs();
    afish();
    return 0;
}
