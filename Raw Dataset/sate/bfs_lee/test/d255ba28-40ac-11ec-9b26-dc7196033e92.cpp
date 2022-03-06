//#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using	 namespace std;
fstream f("sate.in");
ofstream o("sate.out");
int n, m, x, y, d;
int p1, p2;
vector<int> v[30025];
vector<int> distante[30025];
queue<int> coada;
bool vizitat[30025];
vector<int>ans(30025, 0);
int len = 0;

void bfs()
{
	int start;
	while (!coada.empty())
	{
		int nod = coada.front();
		coada.pop();

		for (size_t i = 0; i < v[nod].size(); i++)
		{
			int vecin = v[nod][i];
			if (vizitat[vecin] == false)
			{
				vizitat[vecin] = true;
				coada.push(vecin);
				if (vecin > nod)
				{
					ans[vecin] = ans[nod] + distante[nod][i];
				}
				else
				{
					ans[vecin] = ans[nod] - distante[nod][i];
				}
			}
		}
	}
}

int main()
{
	f >> n >> m >> x >> y;
	for (size_t i = 0; i < m; i++)
	{
		f >> p1 >> p2 >> d;
		v[p1].push_back(p2);
		v[p2].push_back(p1);
		distante[p1].push_back(d);
		distante[p2].push_back(d);
	}

	coada.push(x);
	bfs();
	o << ans[y];
}

