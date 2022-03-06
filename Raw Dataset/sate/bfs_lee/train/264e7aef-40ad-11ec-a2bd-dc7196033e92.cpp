#define DM 30001
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

ifstream fi ("sate.in");
ofstream fo ("sate.out");
int n, m, x, y, dist[DM], a, b, d;
queue <int> q;
vector <pair <int, int> > v[DM];

int main()
{
	fi >> n >> m >> x >> y;
	for (int i = 1; i <= m; ++i)
	{
		fi >> a >> b >> d;
		if (a > b)
			swap(a, b);
		v[a].push_back(make_pair(b, d));
		v[b].push_back(make_pair(a, -d));
	}
	for (int i = 1; i <= n; ++i)
		dist[i] = (1<<30);
	dist[x] = 0;
	q.push(x);
	while(!q.empty())
	{
		a = q.front();
		q.pop();
		for (int i = 0; i < v[a].size(); ++i)
			if (dist[v[a][i].first] > dist[a] + v[a][i].second)
			{
				dist[v[a][i].first] = dist[a] + v[a][i].second;	
				q.push(v[a][i].first);
			}
	}
	if (dist[y] < 0)
		fo << -dist[y];
	else
		fo << dist[y];
	return 0;
}