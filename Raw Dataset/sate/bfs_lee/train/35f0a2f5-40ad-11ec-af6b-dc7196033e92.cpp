#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

int n,m,xs,xf;
vector<pair<int,int>> L[30005];
int D[30005],U[30005];

void read(){
    int x,y,t;
    in>>n>>m>>xs>>xf;
    for(int i=1;i<=m;i++){
        in>>x>>y>>t;
        L[x].push_back({y,t});
        L[y].push_back({x,-t});
    }
}
void bfs(int st){
    int nod;
    queue<int> Q;
    Q.push(st);
    U[st]=1;
    while(!Q.empty()){
        nod=Q.front();
        Q.pop();
        for(auto x : L[nod]){
            if(U[x.first]==0){
                U[x.first]=1;
                D[x.first]=D[nod]+x.second;
                Q.push(x.first);
            }
        }
    }
}
void solve(){
    bfs(xs);
    out<<D[xf];
}
int main(){
    read();
    solve();
    return 0;
}
