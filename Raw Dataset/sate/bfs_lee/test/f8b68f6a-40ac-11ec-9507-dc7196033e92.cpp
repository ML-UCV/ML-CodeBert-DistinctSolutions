#include <fstream>
#include <ctype.h>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
typedef unsigned int uint;

class InParser
{
private:
	FILE *fin;
	char *buff;
	int sp;
	char read_ch()
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
	InParser(const char* nume)
	{
		fin = fopen(nume, "r");
		buff = new char[4096]();
		sp = 4095;
	}
	InParser& operator >> (int &n)
	{
		char c;
		while (!isdigit(c = read_ch()) && c != '-');
		int sgn = 1;
		if (c == '-')
		{
			n = 0;
			sgn = -1;
		}
		else
		{
			n = c - '0';
		}
		while (isdigit(c = read_ch()))
		{
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

	int n,m,start,dest;
	fin >> n >> m >> start >> dest;

	struct cost
	{
		int node,weight;
	};
	vector<cost> adj[n + 1];

	{
		int x,y,c;
		for (uint i = 0; i < m; ++i)
		{
			fin >> x >> y >> c;
			adj[x].push_back({y,c});
			adj[y].push_back({x,-c});
		}
	}

	int dist[n + 1];
	memset(dist, 0, sizeof(dist));
	dist[start] = 1;

	queue<uint> Q;
	Q.push(start);

	while (!dist[dest])
	{
		uint n = Q.front();
		Q.pop();

		for (auto &i : adj[n])
		{
			if (!dist[i.node])
			{
				dist[i.node] = i.weight + dist[n];
				Q.push(i.node);
			}
		}
	}

	fout << dist[dest] - 1;
}
