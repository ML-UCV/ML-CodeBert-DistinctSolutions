#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
vector < pair <int, int> > v[30005];
int n, m, x, y, a, b, dist[30005],i,c,k;
queue <int> q;
int main()
{
	f >> n >> m >> x >> y;
	for (i = 1; i <= m; i++)
	{
		f >> a >> b>>c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,-c });
	}
	q.push(x);
	while (!q.empty())
	{
		k = q.front();
		for (i = 0; i < v[k].size(); i++)
		{
			if (dist[v[k][i].first] == 0)
			{
				dist[v[k][i].first] = dist[k] + v[k][i].second;
				q.push(v[k][i].first);
				if (v[k][i].first == y)
				{
					g << dist[y];
					return 0;
				}
			}
		}
		q.pop();
	}
}