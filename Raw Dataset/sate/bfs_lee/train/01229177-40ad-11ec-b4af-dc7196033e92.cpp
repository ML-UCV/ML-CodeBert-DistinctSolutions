#include <bits/stdc++.h>

using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");
const int N = 100050;


vector < pair<int, int> > v[N];
int d[N];
queue <int> q;
int n,m,ns,nf,vecin;
bool viz[N];
int main()
{
	in>>n>>m>>ns>>nf;
	for (int i = 1;i <= m;i++)
	{
	    int x1,y1,dist;
		in>>x1>>y1>>dist;
		v[x1].push_back({y1,dist});
		v[y1].push_back({x1,(-1)*dist});
	}
	q.push(ns);
	while (!q.empty())
	{
		vecin=q.front(); q.pop();
		for (int i=0;i<v[vecin].size();i++)
		{
			if (viz[v[vecin][i].first]==0)
			{
				viz[v[vecin][i].first] = 1;
				q.push(v[vecin][i].first);
				d[v[vecin][i].first] = d[vecin]+v[vecin][i].second;
			}
		}
	}
	out<<d[nf];
	return 0;
}
