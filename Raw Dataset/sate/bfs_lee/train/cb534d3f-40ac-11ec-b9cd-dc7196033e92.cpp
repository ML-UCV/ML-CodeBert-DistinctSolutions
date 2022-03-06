#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int n, m, x, y, gasit;

vector<int> ocupat(30001, 0);

vector<int> d(30001, 2147483646);

struct muchie
{
	int el, cost;
	muchie(int el, int cost)
		: el(el), cost(cost)
	{
	}
};

struct comp
{
	bool operator()(muchie const& p1, muchie const& p2)
	{
		return p1.cost > p2.cost;
	}

};

priority_queue<muchie, vector<muchie>, comp> coada;

vector<vector<muchie> > liste(30001, vector<muchie>());

int main()
{
	fin >> n >> m >> x >> y;

	for (int i = 1; i <= m; i++)
	{
		int a, b, c;

		fin >> a >> b >> c;

		muchie x(b, c);   muchie y(a, c);

		if (a > b)
			x.cost *= -1;

		else
			y.cost *= -1;

		liste[a].push_back(x);

		liste[b].push_back(y);
	}

	muchie p(x, 0);

	coada.push(p);

	d[x] = 0;

	while (!coada.empty())
	{
		muchie top = coada.top();

		coada.pop();

		for (int i = 0; i < liste[top.el].size(); i++)
		{
			int dest = liste[top.el][i].el, c = liste[top.el][i].cost;

			if (d[dest] > d[top.el] + c)
			{
				d[dest] = d[top.el] + c;

				muchie x(liste[top.el][i].el, d[dest]);

				coada.push(x);
			}
		}
	}

	fout << d[y];
}