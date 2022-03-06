#include <bits/stdc++.h>

using namespace std;


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
};

InParser fin ("sate.in");
ofstream fout ("sate.out");

int n, m, d[30002], viz[30002], x, y;
vector<pair<int, int> > G[30002];

int bfs (int x) {
  viz[x] = 1;
  queue<int>q;
  q.push(x);
  while (!q.empty()) {
    int nod = q.front();
    q.pop();
    for (auto it : G[nod]) {
      if (!viz[it.first]) {
        viz[it.first] = 1;
        d[it.first] = d[nod] + it.second;
        q.push(it.first);
      }
    }
  }
  return abs(d[y]);
}

int main()
{
  fin >> n >> m >> x >> y;
  for (int i = 1; i <= m; i++) {
    int x, y, d;
    fin >> x >> y >> d;
    G[x].push_back({y, d});
    G[y].push_back({x, -d});
  }
  fout << bfs(x);
  return 0;
}
