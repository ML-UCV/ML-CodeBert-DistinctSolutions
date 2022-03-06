#include <bits/stdc++.h>

using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");

queue<int>q;
vector<pair<int,int> >v[30005];
int n,m,inceput,finall,xx,yy,cost,suma,k;
bool viz[30005];
pair<int,int>lant[30005];
//void dfs(int nod,int destinatie){
//	viz[nod]=1;
//	for(auto i:v[nod]){
//		if(viz[i.first]==0){
//			if(nod<i.first)
//				suma+=i.second;
//			else
//				suma-=i.second;
//			if(i.first==destinatie)return;
//            dfs(i.first,destinatie);
//		}
//	}
//}
void bfs(int nod,int destinatie){
	viz[nod]=1;
	lant[nod].first=-1;
	q.push(nod);
    while(!q.empty()){
		k=q.front();
		//cout<<k;
        q.pop();
        for(auto i:v[k]){
			if(viz[i.first]==0){
				lant[i.first]={k,i.second};
				q.push(i.first);
				viz[i.first]=1;
				if(i.first==destinatie)return;
			}
        }

    }
}

int main()
{
	fin>>n>>m>>inceput>>finall;
	for(int i=1;i<=m;i++){
		fin>>xx>>yy>>cost;
		v[xx].push_back({yy,cost});
		//cout<<v[xx][yy].second<<'\n';
		v[yy].push_back({xx,cost});
	}
    bfs(inceput,finall);
    while(lant[finall].first!=-1){
		//cout<<finall;
		if(finall>lant[finall].first)
			suma+=lant[finall].second;
		else
			suma-=lant[finall].second;
		finall=lant[finall].first;
		//cout<<finall<<' '<<suma<<'\n';
    }
    fout<<suma;
    return 0;
}
