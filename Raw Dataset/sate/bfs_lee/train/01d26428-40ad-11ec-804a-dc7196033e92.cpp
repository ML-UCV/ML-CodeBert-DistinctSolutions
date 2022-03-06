#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
const int INF=(1<<30);
const int Maxx=3e4+1;
struct graph{
    int node,cost;
}/*nw,ac*/;
vector <graph> A[Maxx];
vector <graph>::iterator it;
queue <int> Q;
ifstream fin("sate.in");
ofstream fout("sate.out");
int n,m,from,to,i,ac,nw;
int x,y,cost;
int dp[Maxx];
void dijkstra(int from){
    Q.push(from);
    dp[from]=0;
    while (!Q.empty()){
        ac=Q.front();
        Q.pop();
        for (i=0;i<A[ac].size();++i){
            nw=A[ac][i].node;
            if (dp[nw]>A[ac][i].cost+dp[ac]){
                dp[nw]=A[ac][i].cost+dp[ac];
                Q.push(nw);
            }
        }
    }
}
int main() {
    fin>>n>>m>>from>>to;
    for (;m;--m){
        fin>>x>>y>>cost;
        A[x].push_back({y,cost});
        A[y].push_back({x,-cost});
    }
    for (i=1;i<=n;++i) dp[i]=INF;
    dijkstra(from);
    fout<<dp[to];
    return 0;
}
