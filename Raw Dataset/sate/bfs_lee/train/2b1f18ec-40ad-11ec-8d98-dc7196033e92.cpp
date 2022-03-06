//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

typedef struct _NODE
{
	vector<pair<int, int>> neighbours;
	bool visited = false;
	int cost = 0;
}NODE, *PNODE;

NODE G[30005];

int main()
{
	int n, m, x, y, i, a, b, d;
	queue<int> Q;

	fin >> n >> m >> x >> y;
	for (i = 0; i < m; ++i)
	{
		fin >> a >> b >> d;
		G[a].neighbours.push_back(make_pair(b, d));
		G[b].neighbours.push_back(make_pair(a, d));
	}

	Q.push(x);
	G[x].visited = true;
	while (!Q.empty())
	{
		a = Q.front();
		if (a == y) break;
		for (pair<int, int> neighbour : G[a].neighbours)
		{
			if (!G[neighbour.first].visited)
			{
				if (neighbour.first > a)
				{
					G[neighbour.first].cost = G[a].cost + neighbour.second;
				}
				else
				{
					G[neighbour.first].cost = G[a].cost - neighbour.second;
				}
				G[neighbour.first].visited = true;
				Q.push(neighbour.first);
			}
		}
		Q.pop();
	}

	fout << G[y].cost << "\n";

	return 0;
}