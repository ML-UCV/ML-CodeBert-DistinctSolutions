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

vector < pair < int, int > > a[30005];

void bfs(int k, int finish)
{
    if(k == finish) {
        fout << "0";
        exit(0);
    }
    vector < bool > f(30005);
    vector < int > d(30005);
    queue < int > q;
    q.push(k);
    f[k] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(auto v : a[x]) {
            int to = v.first;
            int w = v.second;
            if(!f[to]) {
                f[to] = true;
                d[to] = d[x] + w;
                if(to == finish) {
                    fout << d[to];
                    exit(0);
                }
                q.push(to);
            }
        }
    }
}

int main()
{
    int n, m, f, l;
    fin >> n >> m >> f >> l;
    for(int i = 1; i <= m; ++i) {
        int x, y, w;
        fin >> x >> y >> w;
        a[x].push_back({y, w});
        a[y].push_back({x, -w});
    }
    bfs(f, l);
    return 0;
}
