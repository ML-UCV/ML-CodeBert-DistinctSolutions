#include<bits/stdc++.h>
#define N 30100
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

vector < pair<int, int> > V[N];
int n, m, c, a , b, x, y;
int viz[N];

void DFS(int x) {
	
	for (int i=0; i<V[x].size(); i++) {
	      int fs=V[x][i].first;
	      int cost=V[x][i].second;
	      if (!viz[fs]) {
	      	  viz[fs]=viz[x]+cost;
	      	  DFS(fs);
		  }
	      
}
}
int main() {
	fin>>n>>m>>x>>y;
	if(y<x) swap(x,y);
	for (int i=0; i<m; i++) {
		fin>>a>>b>>c;
	    V[a].push_back(make_pair(b,c));
	    V[b].push_back(make_pair(a,-c));
	}
	DFS(x);
	fout << viz[y];
	return 0;
}

