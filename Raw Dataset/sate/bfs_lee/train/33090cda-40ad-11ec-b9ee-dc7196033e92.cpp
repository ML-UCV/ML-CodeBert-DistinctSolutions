#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#define N 30005
#define mp make_pair
#define f first
#define s second
using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");
bitset<N> v2;
vector<pair<int,int> > v[N];
queue<int> q;
int n, m, x, y, d[N];

void bfs(){
    q.push(x);
    v2[x]=1;
    while(!q.empty()&&!v2[y]){
        x=q.front();
        q.pop();
        for(int i=0; i<v[x].size(); i++){
            if(!v2[v[x][i].f]){
                v2[v[x][i].f]=1;
                d[v[x][i].f]=d[x]+(x<v[x][i].f?v[x][i].s:-v[x][i].s);
                q.push(v[x][i].f);
            }
        }
    }
}

int main(){
    in>>n>>m>>x>>y;
    int a, b, c;
    for(int i=1; i<=m; i++){
        in>>a>>b>>c;
        v[a].push_back(mp(b, c));
        v[b].push_back(mp(a, c));
    }
    bfs();
    out<<d[y];
    return 0;
}
