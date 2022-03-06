#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m;

vector<int> gra[100041];

vector<int> tra[100041];



bool vi[100041];

stack<int> sta;

void defeseta(int a){

 vi[a] = true;

 for(auto b : gra[a]){

  if(!vi[b])defeseta(b);

 }

 sta.push(a);

}



vector<vector<int>> ans;

void defetista(int a, vector<int> &v){

 vi[a] = false;

 v.push_back(a);

 for(auto b : tra[a]){

  if(vi[b])defetista(b, v);

 }

}



int main(){



 fin >> n >> m;

 for(int i = 0; i < m; ++i){

  int a, b;fin>> a >> b;

  gra[a].push_back(b);

  tra[b].push_back(a);

 }



 for(int i = 1; i <= n; ++i){

  if(!vi[i])defeseta(i);

 }

 while(!sta.empty()){

  if(vi[sta.top()]){

   ans.push_back({});

   defetista(sta.top(), ans.back());

  }

  sta.pop();

 }



 fout << ans.size() << "\n";

 for(auto v : ans){

  for(auto a : v){

   fout << a << " ";

  }

  fout << "\n";

 }

 return 0;

}
