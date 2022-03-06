#include<bits/stdc++.h>
#define N 30020
using namespace std;
vector <int> lda[N];
int v[N], l[N], rs[N], dr=1, d;
void bfs(int st){
	if(st<=dr){
		int n=lda[l[st]].size();
		for(int i=0;i<n;i+=2){
			int x=lda[l[st]][i];
		if(!v[x]){
			v[x]=1;
			l[++dr]=x;
			if(l[st] > x)rs[x]=rs[l[st]]-lda[l[st]][i+1]; else rs[x]=rs[l[st]]+lda[l[st]][i+1];
			if(x==d){
				st=dr;
				break;
			}
		}
	}
		bfs(st+1);
	}
}
int main(){
	int n, m, x, y, s, ds;
	freopen("sate.in", "r", stdin);
	freopen("sate.out", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &s, &d);
	while(m--){
		scanf("%d%d%d", &x, &y, &ds);
		lda[x].push_back(y);
		lda[x].push_back(ds);
		lda[y].push_back(x);
		lda[y].push_back(ds);
	}
	l[1]=s;
	bfs(1);
	printf("%d", rs[d]);
	return 0;
}
