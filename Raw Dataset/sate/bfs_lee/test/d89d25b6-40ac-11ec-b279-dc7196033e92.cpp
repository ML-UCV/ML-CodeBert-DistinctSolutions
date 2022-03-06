#pragma GCC optimize("O3")

#include <fstream>
#include <vector>
#include <queue>

using namespace std;

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

InParser in("sate.in");
ofstream out("sate.out");

int n, m, x, y;
vector<pair<int, int>> G[30005];

bool visited[30005];
queue<pair<int, int>> q;

int main() {
	in >> n >> m >> x >> y;
	for (int i = 1; i <= m; i++) {
		int a, b, d;
		in >> a >> b >> d;
		G[a].push_back({ b, d });
		G[b].push_back({ a, -d });
	}
	q.push({ x, 0 });
	visited[x] = 1;
	while (!q.empty()) {
		pair<int, int> current = q.front();
		if (current.first == y) {
			out << current.second;
			return 0;
		}
		q.pop();
		for (auto edge : G[current.first]) {
			pair<int, int> newState = { edge.first, current.second + edge.second };
			if (!visited[newState.first]) {
				visited[newState.first] = 1;
				q.push(newState);
			}
		}
	}
}