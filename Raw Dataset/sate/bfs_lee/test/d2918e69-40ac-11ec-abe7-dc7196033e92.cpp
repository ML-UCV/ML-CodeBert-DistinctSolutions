#include <bits/stdc++.h>

using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
//------------------------------------------
///Globale
const int NMAX = 30001,INF = 1000000000;
int n,st,dr,d[NMAX];
vector<pair<int,int>>muchii[NMAX];
queue<int>q;
//------------------------------------------
///Functii
void citire();
void rezolvare();
//------------------------------------------
int main()
{
	citire();
	rezolvare();
	return 0;
}
//------------------------------------------
void rezolvare()
{
	if(st > dr)
		swap(st,dr);
	for(int i = 1; i <= n; ++i)
		d[i] = INF;
	d[st] = 0;
	q.push(st);
	while(!q.empty())
	{
		int nod = q.front();
		q.pop();
		for(auto it : muchii[nod])
			if(d[it.first] == INF)
			{
				d[it.first] = d[nod] + it.second;
				q.push(it.first);
			}
	}
	g << d[dr];
}
//------------------------------------------
void citire()
{
	int m;
	f >> n >> m >> st >> dr;
	while(m--)
	{
		int x,y,dist;
		f >> x >> y >> dist;
		if(x > y)
			swap(x,y);
		muchii[x].push_back({y,dist});
		muchii[y].push_back({x,-dist});
	}
}
