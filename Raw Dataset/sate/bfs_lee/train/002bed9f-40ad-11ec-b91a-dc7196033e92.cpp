#include <ctype.h>
#include <queue>
#include <stdio.h>
#include <vector>

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
};

const int MAX_N = 30000;
const int INF = 2e9;

struct Node {
  int u;
  int d;
};
std::vector<Node> G[1 + MAX_N];
int dist[1 + MAX_N];
bool inQ[1 + MAX_N];

int main() {

  InParser fin("sate.in");
  freopen("sate.out", "w", stdout);

  int n, m, x, y;
  fin >> n >> m >> x >> y;
  for (int i = 1; i <= m; i++) {
    int u, v, d;
    fin >> u >> v >> d;
    G[u].push_back(Node{v, d});
    G[v].push_back(Node{u, -d});
  }
  for (int i = 1; i <= n; i++)
	dist[i] = INF;
  dist[x] = 0;
  std::queue<Node> bfQ;
  bfQ.push(Node{x, 0});
  inQ[x] = true;
  while (!bfQ.empty() && !inQ[y]) {
    int a = bfQ.front().u;
    int b = bfQ.front().d;
    for (Node e : G[a]) {
      if (!inQ[e.u]) {
        dist[e.u] = b + e.d;
		inQ[e.u] = true;
		bfQ.push(Node{e.u, dist[e.u]});
      }
    }
	bfQ.pop();
  }

  printf("%d\n", dist[y]);

  fclose(stdin);
  fclose(stdout);

  return 0;
}
