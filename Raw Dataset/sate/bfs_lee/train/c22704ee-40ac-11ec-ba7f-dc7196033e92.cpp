#include <bits/stdc++.h>
std::ifstream fin("sate.in");
std::ofstream fout("sate.out");

int n, m, x, y;
std::vector<std::pair<int, int>> nb[30001];
std::vector<int> dist(30001, 0), viz(30001, -1);

void bfs(int x){
    int i; bool done = false;
    viz[x] = 1;
    std::queue<int> q;
    q.push(x);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(i = 0; i < nb[node].size(); i++){
            int nextNode = nb[node][i].first;
            int distance = nb[node][i].second;
            if(viz[nextNode] == -1){
                viz[nextNode] = 1;
                dist[nextNode] = dist[node] + distance;
                q.push(nextNode);

            if(nextNode == y){
                fout << dist[y];
                done = true;
                break;
            }

            }
    }
    if(done == true)
        break;

    }
}


int main()
{
    int i, a, b, c;
    fin >> n >> m >> x >> y;
    for(i = 0; i < m; i++){
        fin >> a >> b >> c;
        nb[a].push_back(std::make_pair(b, c));
        nb[b].push_back(std::make_pair(a, -c));
    }
    bfs(x);
    return 0;
}