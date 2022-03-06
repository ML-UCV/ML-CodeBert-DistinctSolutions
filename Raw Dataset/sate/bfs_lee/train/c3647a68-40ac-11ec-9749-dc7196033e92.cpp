/**
 * Infoarena - Sate
 */
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 3e4 + 1;

vector<pair<int, int>> adj[MAX_N];

vector<int> distance_from_start(MAX_N, -1);

void bfs(int start_node) {
  distance_from_start[start_node] = 0;
  
  queue<int> traversal;
  traversal.push(start_node);
  
  while (!traversal.empty()) {
    int current_node = traversal.front();
    traversal.pop();

    for (pair<int, int> neighbor : adj[current_node]) {
      if (distance_from_start[neighbor.first] == -1) {
        distance_from_start[neighbor.first] =
            neighbor.first < current_node ? 
            distance_from_start[current_node] - neighbor.second :
            distance_from_start[current_node] + neighbor.second;
        traversal.push(neighbor.first);
      }
    }
  }
}

int main() 
{
	std::ifstream fin("sate.in");
  std::ofstream fout("sate.out");
  int n, m, start_node, end_node;
  fin >> n >> m >> start_node >> end_node;

  for (int i = 0; i < m; i++) {
    int x, y, distance;
    fin >> x >> y >> distance;
    adj[x].push_back({y, distance});
    adj[y].push_back({x, distance});
  }

  bfs(start_node);

  fout << distance_from_start[end_node] << '\n';

  return 0;
}
