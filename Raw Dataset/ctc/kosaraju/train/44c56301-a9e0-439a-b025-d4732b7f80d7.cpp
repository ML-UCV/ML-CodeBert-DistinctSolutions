#include<bits/stdc++.h>



std::ifstream f("ctc.in");
std::ofstream g("ctc.out");


std::stack<int> firstDfsSt;
std::vector<int> G[100005];
std::vector<int> T[100005];
std::vector<int> comps[100005];
std::vector<bool> firstDfsViz(100005), inComp(100005);

int n, m, cnt = 0;


void readData(){
    f >> n >> m;
    int x, y;
    for(int i = 0; i<m; i++){
        f >> x >> y;
        G[x].push_back(y);
        T[y].push_back(x);
    }
}

void dfsFirst(int start){
    firstDfsViz[start] = true;
    for(auto& adj : G[start]){
        if(!firstDfsViz[adj]){
            dfsFirst(adj);
        }
    }
    firstDfsSt.push(start);
}



void dfsSecond(int start){
    inComp[start] = true;
    for(auto& adj : T[start]){
        if(!inComp[adj]){
            dfsSecond(adj);
        }
    }

    comps[cnt].push_back(start);
}


void solve(){
    for(int i = 1; i<=n; i++){
        if(!firstDfsViz[i]){
            dfsFirst(i);
        }
    }

    while(!firstDfsSt.empty()){
        int node = firstDfsSt.top();
        if(!inComp[node]){
            dfsSecond(node);
            cnt ++;
        }else{
            firstDfsSt.pop();
        }
    }
}


void printSolution(){
    g << cnt << '\n';
    for(int i = 0; i<cnt; i++){
        for(const auto& elem : comps[i]){
            g << elem << ' ';
        }
        g << '\n';
    }
}

int main(){
    readData();
    solve();
    printSolution();
    return 0;
}
