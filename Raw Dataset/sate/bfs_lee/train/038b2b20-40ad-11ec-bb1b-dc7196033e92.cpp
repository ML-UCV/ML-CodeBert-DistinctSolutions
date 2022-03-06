#include <bits/stdc++.h>
#define maxLimit 300001
using namespace std;

vector<pair<int,int> >G[maxLimit];

queue<int> coada;

    ifstream fin("sate.in");
    ofstream fout("sate.out");

    int n, m, x, y, a, b, c, viz[maxLimit], cost[maxLimit];

void bfs(int plecare){
    coada.push(plecare);
    cost[plecare]=0;
    viz[plecare]=1;
    int actualNod;
    while(!coada.empty()){
        actualNod=coada.front();
        for(int i=0;i<G[actualNod].size();i++){
            if(viz[G[actualNod][i].first]==0){
                coada.push(G[actualNod][i].first);
                cost[G[actualNod][i].first]=cost[actualNod]+G[actualNod][i].second;
                viz[G[actualNod][i].first]=1;
            }
        }
        coada.pop();
    }
}

int main()
{
    fin>>n>>m>>x>>y;
    for(int i=1;i<=m;i++)
    {
        fin>>a>>b>>c;
        G[a].push_back({b,c});
        G[b].push_back({a,(-1)*c});
    }
    bfs(x);
    fout<<cost[y];
    return 0;
}
