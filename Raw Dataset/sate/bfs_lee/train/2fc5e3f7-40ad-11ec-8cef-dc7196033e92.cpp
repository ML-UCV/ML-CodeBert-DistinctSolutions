#include<bits/stdc++.h>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
int n,m,x,y,c,viz[30001],d[30001],v[30001],nod1,nod2;
vector< pair < int , int > >my[30001];
queue<int> q;
inline void bfs(int st){
		int nod,vecin,cost;
		vector< pair<int,int> >::iterator it;
		q.push(st);
		v[st]=1;
		viz[st]=1;
			while (!q.empty()&&!v[nod2]){
								nod=q.front();
								viz[nod]=1;
								q.pop();
								for (it=my[nod].begin();it!=my[nod].end();it++){
																				vecin=(*it).first;
																				cost=(*it).second;
																				if (!viz[vecin]){
																									if (!v[vecin]) if (vecin<nod) v[vecin]=v[nod]-cost;
																														else  v[vecin]=v[nod]+cost;
																									q.push(vecin);
																								}
																				}
							}
}

int main(){
fin>>n>>m>>nod1>>nod2;
for (int i(1);i<=m;i++){
        fin>>x>>y>>c;
        my[x].push_back(make_pair(y,c));
        my[y].push_back(make_pair(x,c));
    }
    bfs(nod1);
fout<<abs(v[nod1]-v[nod2]);
}
