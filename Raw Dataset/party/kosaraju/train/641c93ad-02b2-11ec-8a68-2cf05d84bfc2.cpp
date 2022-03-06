#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
const int NMAX=205;
vector <int> g[NMAX], gt[NMAX];
int n, k, x, y, z, u, i;
int t[NMAX], sol[NMAX];
bool vis[NMAX];
int neg(int x)
{
    if(x<=n)return x+n;
    else return x-n;
}
int DFS(int node)
{
    vis[node]=1;
    for(vector<int>::iterator it=g[node].begin(); it!=g[node].end(); it++)
        if(!vis[*it])DFS(*it);
    ++u;
    t[u]=node;
}
int DFST(int node)
{
    sol[node]=0;
    sol[neg(node)]=1;
    vis[node]=0;
    for(vector<int>::iterator it=gt[node].begin(); it!=gt[node].end(); it++)
        if(vis[*it])DFST(*it);

}
int main()
{
    ifstream cin("party.in");
    ofstream cout("party.out");
    cin>>n>>k;
    for(i=1; i<=k; i++)
    {
        cin>>x>>y>>z;
        if(z==0)
        {
            gt[x].push_back(neg(y));
            gt[y].push_back(neg(x));
            g[neg(x)].push_back(y);
            g[neg(y)].push_back(x);
        }
        else if(z==1)
        {
            g[y].push_back(x);
            gt[x].push_back(y);
        }
        else if(z==2)
        {
            g[x].push_back(y);
            gt[y].push_back(x);
        }
        else
        {
            g[x].push_back(neg(y));
            g[y].push_back(neg(x));
            gt[neg(x)].push_back(y);
            gt[neg(y)].push_back(x);
        }

    }
    for(i=1; i<=2*n; i++)
        if(!vis[i])
            DFS(i);
    reverse(t+1,t+u+1);
    for(i=1; i<=u; i++)
        if(vis[t[i]]&&vis[neg(t[i])])
            DFST(t[i]);
    int nr=0;
    for(i=1; i<=n; i++)
        if(sol[i])
            nr++;
    cout<<nr<<'\n';
    for(i=1; i<=n; i++)
        if(sol[i])
            cout<<i<<'\n';
    return 0;
}
