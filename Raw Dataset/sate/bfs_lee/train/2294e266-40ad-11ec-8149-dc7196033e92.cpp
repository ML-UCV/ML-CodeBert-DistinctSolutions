#include <bits/stdc++.h>
#define DM 30005
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");

vector<pii>nod[DM];
int n,m,x,y,a,b,d;
queue<pii>Q;
bitset<DM>viz;

int main()
{
    fin>>n>>m>>x>>y;
    for(int i=1;i<=m;++i){
        fin>>a>>b>>d;
        nod[a].pb({b,d});
        nod[b].pb({a,d});
    }
    Q.push({x,0});
    viz[x]=1;

    while(!Q.empty()){
        int nodd = Q.front().x,dist = Q.front().y;
        viz[nodd]=1;
        Q.pop();
        if(nodd==y){
            fout<<dist;
            return 0;
        }
        for(auto it:nod[nodd]) if(!viz[it.x])
            Q.push({it.x,dist+it.y-2*it.y*(it.x<nodd)});
    }
    return 0;
}
