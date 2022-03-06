#include<bits/stdc++.h>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
int sol[30010],x[100050],y[100050],km[100050];
int a,b,n,m;
int main(){
	fin >> n >> m >> a >> b;
	sol[a]=1;
	for (int i=1;i<=m;i++)
		fin >> x[i] >> y[i] >> km[i];
	while (!sol[b]){
		for (int i=1;i<=m;i++){
			if (sol[x[i]] && !sol[y[i]]) sol[y[i]]=sol[x[i]]+km[i];
			else if (!sol[x[i]] && sol[y[i]]) sol[x[i]]=sol[y[i]]-km[i];
		}
	}
	fout << sol[b]-1;
}
