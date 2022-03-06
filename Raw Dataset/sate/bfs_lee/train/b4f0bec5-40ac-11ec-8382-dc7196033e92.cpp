#include <fstream>
#include <vector>
#include <queue> 

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

vector <pair <int, int> > v[30005];

int n, m, x, y, a, b, distanta[30005], c;

queue <int> q;

void Citire()
{
	int a, b, i;
	fin >> n >> m >> x >> y;
	for (i = 1; i <= m; i++)
	{
		fin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,-c });
	}

}

int Rezolvare()
{
	int i;
	q.push(x);
	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		for (i = 0; i < v[k].size(); i++)
		{
			if (distanta[v[k][i].first] == 0)
			{
				distanta[v[k][i].first] = distanta[k] + v[k][i].second;
				q.push(v[k][i].first);
				if (v[k][i].first == y)
				{
					fout << distanta[y];
					return 0;
				}
			}
		}
	}
}

int main()
{
	Citire();
    Rezolvare();
	return 0;
}
