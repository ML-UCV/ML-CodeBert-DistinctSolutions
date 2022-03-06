#include <bits/stdc++.h>
#define Intro ios::sync_with_stdio(0), cin.tie(0)
#define ll long long
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
int const N = 3e4 + 3;
int nr_nodes, nr_edges, node_1, node_2;
ll dist[N];
vector<pair<int, int>> edges[N];
bitset<N> visited;

void find_dist() {
    queue<int> nodes_list;
    nodes_list.push(node_1);
    visited[node_1] = 1;
    while (!nodes_list.empty()) {
        int node = nodes_list.front();
        nodes_list.pop();
        for (auto itr : edges[node]) {
            int neighbour = itr.first, distance = itr.second;
            if (visited[neighbour] == 0) {
                visited[neighbour] = 1;
                if (node > neighbour) {
                    dist[neighbour] = 1LL * dist[node] - distance;
                } else {
                    dist[neighbour] = 1LL * dist[node] + distance;
                }
                nodes_list.push(neighbour);
            }
        }
    }
}

int main() {
    fin >> nr_nodes >> nr_edges >> node_1 >> node_2;
    for (int i = 1; i <= nr_edges; ++i) {
        int source, dest, distance;
        fin >> source >> dest >> distance;
        edges[source].push_back({dest, distance});
        edges[dest].push_back({source, distance});
    }
    find_dist();
    fout << dist[node_2];
    //read the stuff below
    return 0;
}
/* Plan
- read the statement carefully
- write stuff down (observations and ideas)
- consider the methods
- revise the solution before implementing it
- int overflow
- edge cases
- make the implementation clearly
*/
