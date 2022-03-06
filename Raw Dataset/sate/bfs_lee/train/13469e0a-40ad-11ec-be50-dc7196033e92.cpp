#include <bits/stdc++.h>
#define INF 1000000
#define NMAX 30005
#define cst first
#define nod second

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

vector < pair<int,int> > mv[NMAX];
int cost[NMAX];
int viz[NMAX],f;
queue < pair<int,int> > q;

int BFS(int x){
	int i;

	cost[x]=0;
	viz[x]=1;
	q.push(make_pair(0,x));

	while(!q.empty()){
		x=q.front().nod;
		q.pop();

		if(x==f)
			return cost[x];

		for(i=0;i<mv[x].size();i++)
			if(!viz[mv[x][i].nod]){
				viz[mv[x][i].nod]=1;
				cost[mv[x][i].nod]=cost[x]+mv[x][i].cst;
				q.push(make_pair(cost[mv[x][i].nod],mv[x][i].nod));
			}
	}
}

int main(){
	int n,m,s,x,y,c,i;

	fin>>n>>m>>s>>f;

	for(i=1;i<=m;i++){
		fin>>x>>y>>c;
		if(x<y){
			mv[x].push_back(make_pair(c,y));
			mv[y].push_back(make_pair(-c,x));
		}
		else{
			mv[x].push_back(make_pair(-c,y));
			mv[y].push_back(make_pair(c,x));
		}
	}

	fout<<BFS(s);

    return 0;
}
