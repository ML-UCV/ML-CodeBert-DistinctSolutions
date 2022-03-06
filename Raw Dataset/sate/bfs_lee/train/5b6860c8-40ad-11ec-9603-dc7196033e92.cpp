#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int N, M, X, Y;
vector <pair < int, int> > nod[30005];
bool viz[30005];
queue <pair<int, long> > coada;
void bfs(){
	while(!coada.empty()){
			int node = coada.front().x;
			long suma = coada.front().y;
			coada.pop(); 
			for(int i=0; i<nod[node].size(); ++i){
				if(!viz[nod[node].at(i).x]){
					viz[nod[node].at(i).x] = 1;
				      if(nod[node].at(i).x>node) coada.push(make_pair(nod[node].at(i).x,suma+nod[node].at(i).y));
					  else   coada.push(make_pair(nod[node].at(i).x,suma-nod[node].at(i).y));
		  		 	  if(nod[node].at(i).x==Y){
		  		 	  						if(nod[node].at(i).x>node)   fout<<suma + nod[node].at(i).y;
		  		 	  						else fout<<suma - nod[node].at(i).y;
											return;
											}
				}
			}
	}
}


int main(){
	fin>>N>>M>>X>>Y;
	
	while(M--){
		int a, b, c; fin>>a>>b>>c;
		nod[a].push_back(make_pair(b,c));
		nod[b].push_back(make_pair(a,c));
	}
	coada.push(make_pair(X,0)); viz[X]=1;
	bfs();
	
	return 0;
}
