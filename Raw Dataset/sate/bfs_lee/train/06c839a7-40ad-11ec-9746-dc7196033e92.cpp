#include<bits/stdc++.h>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
int n,m,start,finish,ras;
vector< pair<int,int> > G[30001];
queue<int> Q;
int dp[30001];
void BFS()
{
    Q.push(start);
    dp[start]=1;
    while(!Q.empty())
    {
        int node=Q.front();
        Q.pop();
        for(vector< pair <int, int> >::iterator it=G[node].begin();it<G[node].end();++it)
        {
            pair<int,int> i=*it;
            if(dp[i.first]==0)
            {
                dp[i.first]=dp[node]+i.second;
                Q.push(i.first);
            }
            if(i.first==finish)
                return;
        }
    }
}
int main()
{
    f>>n>>m>>start>>finish;
    while(m--)
    {
        int a,b,v;
        f>>a>>b>>v;
        G[a].push_back(make_pair(b,v));
        G[b].push_back(make_pair(a,-v));
    }
    BFS();
    g<<dp[finish]-1;
}
