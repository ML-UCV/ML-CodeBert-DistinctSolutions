#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m, x, y;
unordered_map<int, vector<pair<int, int>>> g;
vector<int> visited;
queue<int> q;

void bfs() {
	q.push(x);
	while (!q.empty()) {
		int currentVille = q.front();
		q.pop();

		if (currentVille == y) {
			break;
		}

		for (const auto& v : g[currentVille]) {
			if (visited[v.first] == 0) {
				visited[v.first] += visited[currentVille] + v.second;
				q.push(v.first);
			}
		}
	}
}

int main()
{
	ifstream in("sate.in");
	ofstream out("sate.out");

	in >> n >> m >> x >> y;

	visited = vector<int>(n+1, 0);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		in >> a >> b >> c;
		g[a].push_back({ b, c });
		g[b].push_back({ a, -c });
	}

	bfs();

	out << visited[y];
}
