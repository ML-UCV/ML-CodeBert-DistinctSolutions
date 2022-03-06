#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("ctc.in");
ofstream fout("ctc.out");

const int NMAX = 100002;

int n,m,ssc=0,id=1;
int ids[NMAX],low[NMAX];
bool onStack[NMAX],visited[NMAX];
vector <int> g[NMAX],Stack,ans[NMAX];
void dfs(int node) {
    visited[node]=true;
    ids[node]=low[node]=id++;
    onStack[node]=true;
    Stack.push_back(node);
    for(int i=0; i<g[node].size(); i++) {
        int to=g[node][i];
        if(!visited[to])
            dfs(to);
        if(onStack[to]==true)
            low[node]=min(low[node],low[to]);
    }
    if(ids[node]==low[node]) {
        ssc++;
        while((int)Stack.back()!=node) {
            low[(int)Stack.back()]=low[node];
            onStack[(int)Stack.back()]=false;
            ans[ssc].push_back((int)Stack.back());
            Stack.pop_back();
        }
        low[(int)Stack.back()]=low[node];
        onStack[node]=false;
        ans[ssc].push_back((int)Stack.back());
        Stack.pop_back();
    }
}
int main() {
    fin>>n>>m;
    for(int i=1; i<=m; i++) {
        int x,y;
        fin>>x>>y;
        g[x].push_back(y);
    }
    for(int i=1; i<=n; i++)
        if(!visited[i])
            dfs(i);

    fout<<ssc<<"\n";
    for(int i=1; i<=ssc; i++) {
        while(!ans[i].empty()) {
            fout<<ans[i].back()<<" ";
            ans[i].pop_back();
        }
        fout<<"\n";
    }
    return 0;
}
