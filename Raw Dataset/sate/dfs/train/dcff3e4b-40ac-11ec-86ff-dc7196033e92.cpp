#pragma GCC optimize("O3")

#include <fstream>
#include <bitset>
#include <vector>

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
} in ("sate.in");

const int N = 30009;

bitset < N > viz;
vector < pair < short int, int > > adia[N];

int dist[N];

void dfs(int nod) {
    for (auto i : adia[nod]) {
        if (!viz[i.first]) {
            dist[i.first] = dist[nod] + i.second;
            viz[i.first] = 1;
            dfs(i.first);
        }
    }
}

int main()
{
    ofstream fout("sate.out");
    ios_base::sync_with_stdio(NULL);
    fout.tie(0);
    int m;
    int n, x, y;
    in >> n >> m >> x >> y;
    if (x > y)
        swap(x, y);
    int a, b;
    int c;
    while (m--) {
        in >> a >> b >> c;
        adia[a].push_back({b, c});
        adia[b].push_back({a, -c});
    }
    viz[x] = 1;
    dfs(x);
    if (!viz[y])
        return fout << -1, 0;
    fout << dist[y];
    return 0;
}
