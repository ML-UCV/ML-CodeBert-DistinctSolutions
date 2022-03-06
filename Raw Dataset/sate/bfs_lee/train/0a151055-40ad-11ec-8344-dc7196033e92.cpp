#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");

int n,m,x,y,i,j,nr;
int d[30005];
vector<pair<int, int>> adia[30005];
deque<int> q;

int main() {
	
	fin>>n>>m>>x>>y;
	while(m--)
	{
		fin>>i>>j>>nr;
		adia[i].push_back({j, nr});
		adia[j].push_back({i, nr});
	}
	
	d[x]=1;
	q.push_back(x);
	while(!q.empty())
	{
		x=q.front();
		q.pop_front();
		for(auto i: adia[x])
			if(d[i.first]==0)
			{
				nr=(i.first<x) ? -1 : 1;
				d[i.first]=d[x]+nr*i.second;
				q.push_back(i.first);
			}
	}
	fout<<d[y]-1<<"\n";
}
