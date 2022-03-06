#include <bits/stdc++.h>
#define nmax 30005
using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");
vector<pair<int,int> > lista[nmax];
int n,m,x,y,dp[nmax];
bool ap[nmax];
queue <int> q;
void read()
{
    in >> n >> m >> x >> y;
    for(int i=1; i<=m; i++)
    {
        int a,b,c;
        in >> a >> b >> c;
        lista[a].push_back({b,c});
        lista[b].push_back({a,c});
    }
}
void bfs()
{
    q.push(x);
    ap[x]=1;
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        for(auto x:lista[nod])
        {
            int vecin = x.first;
            int cost = x.second;
            if(!ap[vecin])
            {
                if(vecin<nod)
                {
                    dp[vecin]=dp[nod]-cost;
                }
                else
                {
                    dp[vecin]=dp[nod]+cost;
                }
                ap[vecin]=1;
                if(vecin == y)
                {
                    out << dp[y];
                    return;
                }
                q.push(vecin);
            }
        }
    }
    out << dp[y];
}
int main()
{
    read();
    bfs();
    return 0;
}
