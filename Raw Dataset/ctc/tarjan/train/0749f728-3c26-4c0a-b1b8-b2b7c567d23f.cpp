#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <bitset>

using namespace std;

ifstream f("ctc.in");
ofstream g("ctc.out");

const int NMAX = 100001;

int N, M, cnt, level[NMAX], low[NMAX], cmp;
vector < int > G[NMAX], components[NMAX];
bitset < NMAX > vis, InStack;
stack < int > Stack;

void dfs(const int& node) {

    cnt++;
    level[node] = cnt;
    low[node] = cnt;
    vis[node] = 1;
    Stack.push(node);
    InStack[node] = 1;

    for(const int& neighbor : G[node]) {
        if(level[neighbor] == 0) {
            dfs(neighbor);
            low[node] = min(low[node], low[neighbor]);
        }else if(InStack[neighbor]) {
            low[node] = min(low[node], low[neighbor]);
        }
    }

    if(low[node] == level[node]) {

       cmp++;

       int x{};
       do {
           x = Stack.top();
           Stack.pop();
           InStack[x] = 0;
           components[cmp].push_back(x);
       }while(x != node);
    }
}

int main() {

    f >> N >> M;

    while(M--) {
        int u, v;
        f >> u >> v;

        G[u].push_back(v);
    }

    for(int i = 1;i <= N;++i)
        if(!vis[i])
            dfs(i);

    g << cmp << '\n';
    for(int i = 1;i <= cmp;++i, g << '\n')
        for(const int& it : components[i])
            g << it << ' ';

    return 0;
}
