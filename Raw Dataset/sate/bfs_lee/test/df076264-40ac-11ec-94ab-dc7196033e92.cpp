#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30005;

vector<pair<int, int> >G[MAXN];
int dist[MAXN];
int vis[MAXN];

class InParser {
private:
	FILE *fin;
	char *buff;
	int sp;

	char read_ch() {
		++sp;
		if (sp == 4096) {
			sp = 0;
			fread(buff, 1, 4096, fin);
		}
		return buff[sp];
	}

public:
	InParser(const char* nume) {
		fin = fopen(nume, "r");
		buff = new char[4096]();
		sp = 4095;
	}

	InParser& operator >> (int &n) {
		char c;
		while (!isdigit(c = read_ch()) && c != '-');
		int sgn = 1;
		if (c == '-') {
			n = 0;
			sgn = -1;
		} else {
			n = c - '0';
		}
		while (isdigit(c = read_ch())) {
			n = 10 * n + c - '0';
		}
		n *= sgn;
		return *this;
	}

	InParser& operator >> (long long &n) {
		char c;
		n = 0;
		while (!isdigit(c = read_ch()) && c != '-');
		long long sgn = 1;
		if (c == '-') {
			n = 0;
			sgn = -1;
		} else {
			n = c - '0';
		}
		while (isdigit(c = read_ch())) {
			n = 10 * n + c - '0';
		}
		n *= sgn;
		return *this;
	}
} in ("sate.in");

int main() {
  freopen("sate.out", "w", stdout);

  int n, m, x, y;
  in >> n >> m >> x >> y;
  for (int i = 1; i <= m; ++i) {
    int u, v, c;
    in >> u >> v >> c;
    G[u].push_back({v, c});
    G[v].push_back({u, -c});
  }

  queue<int>q;
  q.push(x);
  vis[x] = 1;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto it:G[node])
      if (vis[it.first] == 0) {
        vis[it.first] = 1;
        dist[it.first] = dist[node] + it.second;
        q.push(it.first);
      }
  }

  printf("%d\n", abs(dist[y]));

  return 0;
}
