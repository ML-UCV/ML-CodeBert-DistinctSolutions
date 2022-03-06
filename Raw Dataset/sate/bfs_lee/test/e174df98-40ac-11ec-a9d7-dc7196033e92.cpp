#include <bits/stdc++.h>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
int n,m,x,y,X,Y,D,sum[30005];
vector<pair<int,int> >v[30005];
bitset<30005>viz;
queue<int>q;
string s;
void bfs(int x)
{
    q.push(x);
    viz[x]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(int i=0; i<v[x].size(); i++)
            if(viz[v[x][i].first]==0)
            {
                q.push(v[x][i].first);
                viz[v[x][i].first]=1;
                sum[v[x][i].first]=sum[x]+v[x][i].second;
                if(v[x][i].first==y)
                    return;
            }
    }
}
int main()
{
    f>>n>>m>>x>>y;
    getline(f,s);
    for(int i=1; i<=m; i++)
    {
        getline(f,s);
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            int nr=0;
            cnt++;
            while('0'<=s[i] && s[i]<='9')
                nr=nr*10+(s[i]-'0'),i++;
            if(cnt==1)
                X=nr;
            else if(cnt==2)
                Y=nr;
            else
                D=nr;
        }
        v[X].push_back({Y,D});
        v[Y].push_back({X,-D});
    }
    bfs(x);
    g<<sum[y];
    return 0;
}
