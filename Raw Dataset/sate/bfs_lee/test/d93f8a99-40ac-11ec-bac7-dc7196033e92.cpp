#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <ctype.h>

#define pi pair<int,int>

using namespace std;

const int nmax = 3e4 + 5;

vector<pi>l[nmax];
queue<int>q;
bool viz[nmax];
int ans[nmax];

int solve(int x, int y) {
	q.push(x);
	viz[x] = 1;
	while (!q.empty()) {
		int z = q.front();
		q.pop();
		for (auto t : l[z])
			if (!viz[t.first]) {
				viz[t.first] = 1;
				ans[t.first] = ans[z] + t.second;
				q.push(t.first);
				if (t.first == y)
					return ans[y];
			}
	}
}

class InParser {
private:
	FILE* fin;
	char* buff;
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

	InParser& operator >> (int& n) {
		char c;
		while (!isdigit(c = read_ch()) && c != '-');
		int sgn = 1;
		if (c == '-') {
			n = 0;
			sgn = -1;
		}
		else {
			n = c - '0';
		}
		while (isdigit(c = read_ch())) {
			n = 10 * n + c - '0';
		}
		n *= sgn;
		return *this;
	}

	InParser& operator >> (long long& n) {
		char c;
		n = 0;
		while (!isdigit(c = read_ch()) && c != '-');
		long long sgn = 1;
		if (c == '-') {
			n = 0;
			sgn = -1;
		}
		else {
			n = c - '0';
		}
		while (isdigit(c = read_ch())) {
			n = 10 * n + c - '0';
		}
		n *= sgn;
		return *this;
	}
};

int main()
{
	InParser fin("sate.in");
	ofstream fout("sate.out");
	int n, m, x, y, u, v, d;
	fin >> n >> m >> x >> y;
	for (int i = 1; i <= m; i++) {
		fin >> u >> v >> d;
		l[u].push_back({ v,d });
		l[v].push_back({ u,-d });
	}
	if (x == y) {
		fout << 0;
		return 0;
	}
	fout << solve(x,y);
}