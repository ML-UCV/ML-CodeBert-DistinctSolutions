#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int N = 100041;



int n, m;

vector<int> gra[N];

int idx[N], lol[N];

bool vi[N];



stack<int> staketa;

vector<vector<int>> answereta;



int indexeta = 1;



void defeseta(int a){

 staketa.push(a);

 idx[a] = indexeta++;

 lol[a] = idx[a];



 vi[a] = true;



 for(auto b : gra[a]){

  if(idx[b] == 0){

   defeseta(b);

   lol[a] = min(lol[a], lol[b]);

  }else if(vi[b]){

   lol[a] = min(lol[a], idx[b]);

  }

 }



 if(lol[a] == idx[a]){

  answereta.push_back({});

  vector<int> &baketa = answereta.back();

  while(staketa.top() != a){

   baketa.push_back(staketa.top());

   vi[staketa.top()] = false;

   staketa.pop();

  }

  baketa.push_back(staketa.top());

  vi[staketa.top()] = false;

  staketa.pop();

 }

}



int main(){



 fin >> n >> m;

 for(int i = 0; i < m; ++i){

  int a, b;

  fin>> a >> b;

  gra[a].push_back(b);

 }



 for(int i = 1; i <= n; ++i){

  if(idx[i]==0)defeseta(i);

 }



 fout << answereta.size() << "\n";

 for(auto v : answereta){

  for(auto a : v){

   fout << a << " ";

  }

  fout << "\n";

 }

 return 0;

}
