#include <bits/stdc++.h>
using namespace std;
ifstream f("sate.in");
ofstream o("sate.out");

int n, m, x, y, d, i, j;
int rez[30009], viz[30009];

vector <pair <int, int> > v[30009];
queue <int> q;

void BFS(int k){
	q.push(k);
	viz[k]=1;
	while(!q.empty()){
		int nod = q.front();
		q.pop();
		for(auto x : v[nod]){
			if(!viz[x.first]){
				q.push(x.first);
				viz[x.first]=1;
				if(nod > x.first)
					rez[x.first] = rez[nod] - x.second;
				else
					rez[x.first] = rez[nod] + x.second;
				if(x.first == y)
					return;
			}
		}
	}
}

int main(){
	f >> n >> m >> x >> y;
	for(int k = 1; k <= m; ++k){
		f >> i >> j >> d;
		v[i].push_back(make_pair(j, d));
		v[j].push_back(make_pair(i, d));
	}
	BFS(x);
	o << rez[y];

	return 0;
}
