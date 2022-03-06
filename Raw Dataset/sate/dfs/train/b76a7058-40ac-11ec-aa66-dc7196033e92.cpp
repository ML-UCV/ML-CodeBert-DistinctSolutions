#include <bits/stdc++.h>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
typedef pair <int, int> ii;
vector <ii> G[30005];
int d[30005], c[30005];
void dfs(int u){
int v, j;
c[u] = 1;
for(j=0;j<G[u].size();j ++){
v=G[u][j].first;
if(!c[v]){
d[v]=d[u]+G[u][j].second;
dfs(v);
}}}
int main(){
int n,m,i,x,y,z,s,t;
f>>n>>m>>s>>t;
for(i=1;i<=m;i++){
f>>x>>y>>z;
G[x].push_back({y,z});
G[y].push_back({x,-z});}
dfs(s);
g<<d[t]-d[s];
return 0;}
