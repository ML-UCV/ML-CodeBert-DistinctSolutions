#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;



int n, m, i, out[300001];

vector<int> graph[250001];

vector<int> v, rad;

vector<pair<int, int> > query[250001];



void read();

void solve();

void dfs(int node);

void write();

int main()

{

    read();

    solve();

    write();

    return 0;

}

void read(){

    freopen("stramosi.in", "r", stdin);

    scanf("%d%d", &n, &m);

    for(i=1; i<=n; ++i){

        int head;

        scanf("%d", &head);

        if(head) graph[head].push_back(i);

        else rad.push_back(i);

    }

    for(i=1; i<=m; ++i){

        int node, p;

        scanf("%d%d", &node, &p);

        query[node].push_back({p, i});

    }

    return;

}

void solve(){

    for(auto j:rad) dfs(j);

    return;

}

void write(){

    freopen("stramosi.out", "w", stdout);

    for(i=1; i<=m; ++i) printf("%d\n", out[i]);

    return;

}

void dfs(int node){

    for(auto i:query[node]){

        if(i.first<=v.size()) out[i.second]=v[v.size()-i.first];

        else out[i.second]=0;

    }

    v.push_back(node);

    for(auto i:graph[node]) dfs(i);

    v.pop_back();

    return;

}
