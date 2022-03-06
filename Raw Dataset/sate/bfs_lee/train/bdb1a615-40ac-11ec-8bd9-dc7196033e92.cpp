#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

std::ifstream in("sate.in");
std::ofstream out("sate.out");


int n, m, x, y;
int dist[1000005];
std::vector<std::pair<int,int>> g[30001];
std::vector<int> bfs;


int main() {
    in >> n >> m >> x >> y;

    for(int i = 1; i <= m; i++)
    {
        int a,b,c;
        in >> a >> b >> c;
        g[a].push_back(std::make_pair(b,c));
        g[b].push_back(std::make_pair(a,-c));
    }


    bfs.push_back(x);
    for(int i = 0; i < bfs.size(); i++) {
        int current_node = bfs[i];
        for(int j = 0; j < g[current_node].size(); j++)
        {
            int node = g[current_node][j].first;
            if(dist[node] == 0)
            {
                dist[node] = dist[current_node] + g[current_node][j].second;
                bfs.push_back(node);
            }
        }
    }

    for(int i = 0; i <= n ;i++)
    std::cout << dist[i] << " ";
    out << dist[y];
    return 0;
}
