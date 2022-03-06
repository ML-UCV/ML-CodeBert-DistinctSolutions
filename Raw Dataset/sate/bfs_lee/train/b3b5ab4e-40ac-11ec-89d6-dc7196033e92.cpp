#include <bits/stdc++.h>
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

const int NMAX = (int)3e5;

vector<pair<int, int>> adj[NMAX+1];
bool vis[NMAX+1];
int dist[NMAX+1];

void bfs(int v) {
	queue<int> q;
	q.push(v);
	vis[v] = 1;
	while(!q.empty()) {
		int e=q.front();
		for(auto i:adj[e]) {
			if(!vis[i.first]) {
				vis[i.first] = true;
				dist[i.first] = dist[e] + i.second;
				q.push(i.first);
			}
		}
		q.pop();
	}
}

int main() {
	int N, M, X, Y;
	fin >> N >> M >> X >> Y;
	for(int i=1;i<=M;i++) {
		int a, b, c;
		fin >> a >> b >> c;
		if(a>b)	swap(a, b);
		adj[a].push_back({b, c});
		adj[b].push_back({a, -c});
	}
	bfs(X);
	fout << dist[Y] << '\n';
	return 0;
}