#include<bits/stdc++.h>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

int visited[100005], visited_t[100005], scc,n,m;
vector <int> edges[100005];
vector <int> edges_t[100005];
vector <int> solution[100005];
stack <int> s;

void dfs(int vertex){
    int i;
    visited[vertex] = 1;
    for(i = 0;i < edges[vertex].size();i++){
        if(!visited[edges[vertex][i]]){
            dfs(edges[vertex][i]);
        }
    }
    s.push(vertex);
}

void dfs_t(int vertex){
    int i;
    visited_t[vertex] = 1;
    solution[scc].push_back(vertex);
    for(i = 0;i < edges_t[vertex].size();i++){
        if(!visited_t[edges_t[vertex][i]]){
            dfs_t(edges_t[vertex][i]);
        }
    }

}

void read(){
    int i,x,y;
    fin>>n>>m;
    for(i=1;i<=m;i++){
        fin>>x>>y;
        edges[x].push_back(y);
        edges_t[y].push_back(x);
    }
}

int main()
{
    read();
    int i,j;
    for(i = 1;i <= n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    while(!s.empty()){
        if(!visited_t[s.top()]){
            scc++;
            dfs_t(s.top());
        }
        s.pop();
    }

    fout<<scc<<"\n";
    for(i = 1;i <= scc;i++){
        for(j = 0;j < solution[i].size();j++){
            fout<<solution[i][j]<<" ";
        }
        fout<<"\n";
    }



    return 0;
}
