#include <iostream>
#include <fstream>
#include <queue>
#include <memory.h>
#include <vector>
#include <list>
#include<stdio.h>
using namespace std;

const int maxn=30005;

ifstream fin("sate.in");
ofstream fout("sate.out");

int n, m, x, y, d, i, j;
int dist[maxn], viz[maxn];

vector <pair <int, int> > v[maxn];
queue <int> q;

void bfs(int s){
	q.push(s);
	viz[s]=1;
	while(!q.empty()){
		int nod = q.front();
		q.pop();
		for(auto x : v[nod]){	
			if(!viz[x.first]){
				q.push(x.first);
				viz[x.first]=1;
				if(nod > x.first)
					dist[x.first] = dist[nod] - x.second;
				else 
					dist[x.first] = dist[nod] + x.second;
				if(x.first == y)
					return;
			}
		}
	}
}

int main(){
	fin >> n >> m >> x >> y;
	for(int k = 1; k <= m; ++k){
		fin >> i >> j >> d;
		v[i].push_back(make_pair(j, d));
		v[j].push_back(make_pair(i, d));
	}
	bfs(x);
	fout << dist[y];
	
	return 0;
}