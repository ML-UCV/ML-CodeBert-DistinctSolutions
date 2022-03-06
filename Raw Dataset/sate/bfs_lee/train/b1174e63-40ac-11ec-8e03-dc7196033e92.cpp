#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int n, m, X, Y;
vector<pair<int, int>> a[30001];
int costdrum;
int dist[30001];

void read() {
	int x, y, cost;
	ifstream f("sate.in");	
	f >> n >> m >> X >> Y;
	for (int i = 1; i <= m; i++) {
		f >> x >> y >> cost;
		a[x].emplace_back(cost, y);
		a[y].emplace_back(-cost, x);
	}
	f.close();
	if (X > Y)
		swap(X, Y);
}

queue<int> Q;
void bfs() {
	int x, i;
	Q.push(X);
	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		for (i = 0; i < a[x].size(); i++)
			if (dist[a[x][i].second] == 0) {
				dist[a[x][i].second] = a[x][i].first + dist[x];
				Q.push(a[x][i].second);
			}

	}
}

void solve() {
	int i;
	bfs();
}

void output() {
	ofstream g("sate.out");
	g << dist[Y];
	g.close();
}

int main() {
	read();
	solve();
	output();
	return 0;
}