#include <iostream>
#include <stack>
#include <vector>
#include <fstream>

using namespace std;

vector<int> ms[100005];
vector<int> invertedms[100005];

stack<int> ns;
int comp[100005];
vector<int> compis[100005];
bool visited[100005];

void dfs(int node){
    if(!visited[node]){
        visited[node] = 1;
        for (auto it : ms[node]) {
            dfs(it);
        }
        ns.push(node);
    }
}

void assign(int n, int c){
    if(comp[n] == 0){
        comp[n] = c;
        compis[c].push_back(n);
        for(auto it : invertedms[n]){
            assign(it, c);
        }
    }
}

int main() {
    int n, m;
    ifstream f("ctc.in");
    ofstream g("ctc.out");
    f>>n>>m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        f>>x>>y;
        ms[x].push_back(y);
        invertedms[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        if(!visited[i]) dfs(i);
    }
    int c = 0;
    while(!ns.empty()) {
        int node = ns.top();
        ns.pop();
        if (comp[node] == 0) {
            ++c;
            assign(node, c);
        }

    }
    --c;
    g<<c<<"\n";
    for (int i = 1; i <= c; ++i) {
        for(auto it : compis[i]){
            g<<it<<' ';
        }
        g<<'\n';
    }
    return 0;
}
