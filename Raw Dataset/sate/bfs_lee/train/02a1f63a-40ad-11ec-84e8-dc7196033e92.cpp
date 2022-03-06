#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define lim 100030
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
vector <pair<int, int> > muc[lim];
int cost[lim];
queue <int> q;
int n,m,x,y,a,b,d,nod;
long long viz[lim];
int main()
{
	f>>n>>m>>x>>y;
	for (int i=1;i<=m;i++)
	{
		f>>a>>b>>d;
		muc[a].push_back({b,d});
		muc[b].push_back({a,(-1)*d});
	}
	q.push(x);
	while (!q.empty())
	{
		nod=q.front();
		q.pop();
		for (int i=0;i<muc[nod].size();i++)
		{
			if (viz[muc[nod][i].first]==0)
			{
				viz[muc[nod][i].first]=1;
				q.push(muc[nod][i].first);
				cost[muc[nod][i].first]=cost[nod]+muc[nod][i].second;
			}
		}
	}
	g<<cost[y];
	f.close();
	g.close();
	return 0;
}
