#include <bits/stdc++.h>
using namespace std;
const int NMAX = 30005;
bool viz[NMAX];
int dist[NMAX];
vector <pair<int, int>> vec[NMAX];
queue <int> q;
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
    int n, m, x, y;
    freopen("sate.out", "w", stdout);
    in >> n >> m >> x >> y;
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        in >> a >> b >> c;
        if(a > b) {
            c = -c;
        }
        vec[a].push_back({b, c});
        vec[b].push_back({a, -c});
    }
    viz[x] = 1;
    q.push(x);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : vec[u]) {
            if(viz[v.first] == 0) {
                dist[v.first] = dist[u] + v.second;
                viz[v.first] = 1;
                q.push(v.first);
            }
        }
    }
    if(dist[y] < 0) {
        dist[y] = -dist[y];
    }
    printf("%d\n", dist[y]);
    return 0;
}
