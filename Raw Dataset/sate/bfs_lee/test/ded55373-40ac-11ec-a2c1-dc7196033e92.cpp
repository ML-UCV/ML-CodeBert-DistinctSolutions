#include <cstdio>
#include <queue>
#include <vector>
#include <ctype.h>

FILE *_fin;
int _in_loc; char _in_buff[4096];


void read_init(const char* nume) {
  _fin = fopen(nume, "r");
	_in_loc = 4095;
}

char read_ch() {
	++_in_loc;
	if (_in_loc == 4096) {
		_in_loc = 0;
		fread(_in_buff, 1, 4096, _fin);
	}
	return _in_buff[_in_loc];
}

int read_u32() {
	int u32 = 0; char c;
	while (!isdigit(c = read_ch()) && c != '-');
	int sgn = 1;
	if (c == '-') {
		sgn = -1;
	} else {
		u32 = c - '0';
	}
	while (isdigit(c = read_ch())) {
		u32 = u32 * 10 + c - '0';
	}
	return u32 * sgn;
}

using namespace std;

const int MAX_N = 30000;

struct Edge {
  int u;
  int cost;
};

bool vis[1 + MAX_N];
vector<Edge> g[1 + MAX_N];
int dist[1 + MAX_N];

void bfs(int start) {
  queue<int> q;

  q.push(start);
  vis[start] = true;
  dist[start] = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (auto e : g[node]) {
      int u, cost;

      u = e.u;
      cost = e.cost;

      if (!vis[u]) {
        q.push(u);
        vis[u] = true;
        dist[u] = dist[node] + cost;
      }
    }
  }
}

int main() {
  read_init("sate.in");
  freopen("sate.out", "w", stdout);

  int n, m, x, y;

  n = read_u32();
  m = read_u32();
  x = read_u32();
  y = read_u32();

  for (int i = 1; i <= m; i++) {
    int u, v, cost;

    u = read_u32();
    v = read_u32();
    cost = read_u32();

    g[u].push_back({v, cost});
    g[v].push_back({u, -cost});
  }

  bfs(x);

  printf("%d\n", dist[y]);
  return 0;
}
