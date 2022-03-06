#include <fstream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;
ifstream fi("party.in");
ofstream fo("party.out");
int N,M;
vector<int> G[2][210];
vector<int> GComp[210];
int WhatComp[210],used[210],NComps,usedComp[210],assoc[210],val[210];
stack<int> S;
vector<vector<int> > Comps;
vector<int> sol;





void make_graph(int x, int y){
 G[0][N-x+1].push_back(y);
 G[1][y].push_back(N-x+1);
 G[0][N-y+1].push_back(x);
 G[1][x].push_back(N-y+1);
}

void afis(int i){
 if ((i*2)<=N) fo<<i; else fo<<"~"<<N-i+1;
 fo<<" ";
}

void get_input(){
 int x,y,z;
 fi>>N>>M;
 N*=2;
 for (int i=1;i<=M;++i){
  fi>>x>>y>>z;
  if (z==0) make_graph(x,y); else
   if (z==1) make_graph(x,N-y+1); else
    if (z==2) make_graph(N-x+1,y); else
     make_graph(N-x+1,N-y+1);
 }
 fi.close();
}



void DFSPlus(int nod,vector<int>* G){
 used[nod]=1;
 vector<int>::iterator it;
 for (it=G[nod].begin();it!=G[nod].end();++it)
  if (!used[*it]) DFSPlus(*it,G);
 S.push(nod);
}



void DFSMinus(int nod,vector<int>* G,int componenta){
 WhatComp[nod]=componenta;
 vector<int>::iterator it;
 for (it=G[nod].begin();it!=G[nod].end();++it)
  if (!WhatComp[*it]) DFSMinus(*it,G,componenta);
}



void topologica(int nod,vector<int>* G){
 used[nod]=1;
 vector<int>::iterator it;
 for (it=G[nod].begin();it!=G[nod].end();++it)
  if (!used[*it]) topologica(*it,G);
 S.push(nod);
}

void get_output(){
 fo<<sol.size()<<"\n";
 for (vector<int>::iterator it=sol.begin();it!=sol.end();++it) fo<<(*it)<<"\n";
 fo.close();
}


int main(){
 get_input();


 memset(used,0,sizeof(used));
 memset(WhatComp,0,sizeof(WhatComp));
 for (int i=1;i<=N;++i) if (!used[i]) DFSPlus(i,G[0]);

 NComps=0;
 while (!S.empty()){
  if (!WhatComp[S.top()]){ ++NComps; DFSMinus(S.top(),G[1],NComps); }
  S.pop();
 }
 Comps.resize(NComps+1);
 for (int i=1;i<=N;++i) Comps[WhatComp[i]].push_back(i);


 for (int i=1;i<=N;++i){
  memset(usedComp,0,sizeof(usedComp));
  for (vector<int>::iterator it=G[0][i].begin();it!=G[0][i].end();++it)
   if (WhatComp[i]!=WhatComp[*it] && !usedComp[WhatComp[*it]]){
    GComp[WhatComp[i]].push_back(WhatComp[*it]);
    usedComp[WhatComp[*it]]=1;
   }
 }
 for (int i=1;i<=N;++i) assoc[WhatComp[i]]=WhatComp[N-i+1];


 memset(used,0,sizeof(used));
 for (int i=1;i<=NComps;++i)
  if (!used[i]) topologica(i,GComp);


 memset(used,0,sizeof(used));
 memset(val,0,sizeof(val));
 while (!S.empty()){
  if (!used[S.top()]){
   for (vector<int>::iterator it=Comps[S.top()].begin();it!=Comps[S.top()].end();++it) { val[*it]=0;val[N-(*it)+1]=1; }
   used[S.top()]=1;
   used[assoc[S.top()]]=1;
  }
  S.pop();
 }

 for (int i=1;(i*2)<=N;++i)
  if (val[i]) sol.push_back(i);

 get_output();

 return 0;
}
