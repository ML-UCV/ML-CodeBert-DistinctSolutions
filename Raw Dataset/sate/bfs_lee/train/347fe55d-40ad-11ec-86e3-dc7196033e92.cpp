#include <cstdio>
#include <vector>
#include <queue>
#define NMax 30003

using namespace std;

vector <pair<int,int> > G[NMax];
queue <int> Q;
bool seen[NMax];
int ans[NMax];

int main()
{
	freopen("sate.in", "r", stdin);
	freopen("sate.out", "w", stdout);
	
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	
	for(int i=1; i<=m; i++)
	{
		int x, y, d;
		scanf("%d%d%d", &x, &y, &d);
		G[x].push_back(make_pair(y, d));
		G[y].push_back(make_pair(x, -d));
	}
	
	seen[a]=1;
	Q.push(a);
	while(!Q.empty())
	{
		int node=Q.front();
		Q.pop();
		for(int i=0; i<G[node].size(); i++)
			if(!seen[G[node][i].first])
			{
				seen[G[node][i].first]=1;
				ans[G[node][i].first]=ans[node]+G[node][i].second;
				Q.push(G[node][i].first);
			}
	}
	printf("%d\n", ans[b]);
	
	return 0;
}
