#include <bits/stdc++.h>
using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");
typedef long long ll;
const int lim=3e4+5;
vector<pair<int,ll> > vec[lim];
int n,m,st,dr,x,y; ll d;
ll dist[lim];
bool ok[lim];
void df(int nod)
{
    ok[nod]=true;
    for(auto x:vec[nod])
    if(!ok[x.first])
        dist[x.first]=dist[nod]+x.second,
        df(x.first);
}
int main()
{
    in>>n>>m>>st>>dr;
    for(int i=1;i<=m;++i)
    {
        in>>x>>y>>d;
        vec[x].push_back({y,d});
        vec[y].push_back({x,-d});
    }
    df(st);
    out<<dist[dr]<<'\n';
    return 0;
}
