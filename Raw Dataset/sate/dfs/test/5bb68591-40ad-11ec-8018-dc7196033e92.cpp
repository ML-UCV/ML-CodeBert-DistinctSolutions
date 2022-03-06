#include <bits/stdc++.h> 
#define mp make_pair
#define pb push_back
#define st first
#define nd second 
#define pii pair <int, int>

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

int n, m, x, y, a, b, c, d[30100]; bool viz[30100];
vector <pii> v[100100];

void dfs(int nod){
	for(auto it : v[nod]){
		if(!viz[it.st]){
			viz[it.st] = 1;
			d[it.st] = d[nod] + it.nd;
			if(it.st == y) return;
			dfs(it.st);
		}
	}
}

int main(){
	in >> n >> m >> x >> y;
	for(int i = 1; i <= m; i++){
		in >> a >> b >> c;
		v[a].pb(mp(b, c));
		v[b].pb(mp(a, -c));
	}
	dfs(x);
	return out << d[y], 0;
}
