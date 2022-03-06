#include <bits/stdc++.h>
#define N 30001

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

struct cod
{
	int destinatie,cost;
}Dudau;
vector<cod> v[N];

int n,m,x,y,a,b,cost;
int vizitat[N];

void BFS(int nod)
{
	queue<int> coada;
	vizitat[nod]=1;
	coada.push(nod);
	while(!coada.empty())
	{
		nod=coada.front();
		coada.pop();
		for(int i=0;i<(int)v[nod].size();++i)
		{
			if(!vizitat[v[nod][i].destinatie])
			{
				vizitat[v[nod][i].destinatie]=vizitat[nod]+v[nod][i].cost;
				coada.push(v[nod][i].destinatie);
			}
		}
	}
}

int main()
{
	fin>>n>>m>>x>>y;
	for( int i=0;i<m;++i)
	{
		fin>>a>>b>>cost;
		if(a>b)
            swap(a,b);
		Dudau.cost=cost;
		Dudau.destinatie=b;
		v[a].push_back(Dudau);
		Dudau.cost=-cost;
		Dudau.destinatie=a;
		v[b].push_back(Dudau);
	}
	BFS(x);
	fout<<vizitat[y]-1;
}
