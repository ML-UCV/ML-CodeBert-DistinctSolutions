#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct edg{

 int a, b, v;

 bool operator<(const edg &rhs)const{

  if(v != rhs.v){

   return v > rhs.v;

  }else if(b != rhs.b){

   return b > rhs.b;

  }else{

   return a > rhs.a;

  }

 }

 int ott(int w){

  if(w == a){

   return b;

  }else if(w == b){

   return a;

  }else{

   return 0;

  }

 }

};



const int N = 200041;



int n, m;

vector<edg> edgs;

vector<int> gra[N];

bool vi[N];



int skibidibapmdada(const edg &ed){

 if(!vi[ed.a]){

  return ed.a;

 }else if(!vi[ed.b]){

  return ed.b;

 }else{

  return 0;

 }

}



priority_queue<edg> pq;

void addme(int a){

 vi[a] = true;

 for(auto edi : gra[a]){

  edg &ed = edgs[edi];

  if(!vi[ed.ott(a)]){

   pq.push(ed);

  }

 }

}



int cost = 0;

vector<edg> naisu;



int main(){





 fin >> n >> m;

 for(int i = 0; i < m; ++i){

  edg ed;

  fin >> ed.a >> ed.b >> ed.v;

  edgs.push_back(ed);

  gra[ed.a].push_back(i);

  gra[ed.b].push_back(i);

 }



 addme(1);

 while(!pq.empty()){

  edg ed = pq.top();

  pq.pop();

  int w = skibidibapmdada(ed);

  if(w != 0){

   cost += ed.v;

   naisu.push_back(ed);

   addme(w);

  }

 }



 fout << cost << "\n";

 fout << naisu.size() << "\n";

 for(auto ed : naisu){

  fout << ed.a << " " << ed.b << "\n";

 }



 return 0;

}
