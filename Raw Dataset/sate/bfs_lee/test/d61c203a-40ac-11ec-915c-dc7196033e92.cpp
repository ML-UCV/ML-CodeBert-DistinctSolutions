#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#pragma warning (disable:4996)
using namespace std;

typedef pair <int, int> p;

const int NMAX = 3 * 1e4 + 2;

class parsare
{
private:
	FILE* fin;
	int sp;
	char* buff;
	char read()
	{
		++sp;
		if (sp == 4096)
		{
			sp = 0;
			fread(buff, 1, 4096, fin);
		}
		return buff[sp];
	}
public:
	parsare(const char* nume)
	{
		sp = 4095;
		fin = fopen(nume, "r");
		buff = new char[4096];
	}
	parsare& operator >> (int& n)
	{
		char c;
		while (!isdigit(c = read()));
		n = c - '0';
		while (isdigit(c = read()))
			n = n * 10 + c - '0';
		return *this;
	}
};

parsare fin("sate.in");
ofstream fout("sate.out");

vector <p> g[NMAX];
int dist[NMAX], d;
int n, m, x, y, a, b;

bitset <NMAX> viz;

queue <int> q;

void solve()
{
	while (!q.empty())
	{
		x = q.front();
		if (x == b)
			return;
		viz[x] = 1;
		q.pop();
		for (size_t i = 0; i < g[x].size(); ++i)
		{
			if (viz[g[x][i].first] == 0)
			{
				dist[g[x][i].first] = dist[x] + g[x][i].second;
				q.push(g[x][i].first);
			}
		}
	}
}

int main()
{
	fin >> n >> m >> a >> b;
	for (int i = 1; i <= m; ++i)
	{
		fin >> x >> y >> d;
		g[x].push_back({ y, d });
		g[y].push_back({ x, -d });
	}
	q.push(a);
	solve();
	fout << dist[b] << "\n";
	return 0;
}