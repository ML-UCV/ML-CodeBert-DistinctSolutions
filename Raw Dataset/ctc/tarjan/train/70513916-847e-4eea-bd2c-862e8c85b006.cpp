#include <iostream>
#include <fstream>
#include <vector>
#include <stack>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



struct Node{

 int index=0, lowlink=0;

 bool onstack = false;

 Node(){}

 Node(int index, int lowlink) : index(index), lowlink(lowlink){

  onstack = true;

 }

};



int n, m;

vector<int> gra[100041];

void read(){

 fin >> n >> m;

 for(int i = 0; i < m; ++i){

  int a, b;

  fin >> a >> b;

  gra[a].push_back(b);

 }

}



vector<vector<int>> components;



stack<int> s;

int index = 1;

Node nodes[100041];

void strongconnect(int a){

 s.push(a);

 Node &an = nodes[a];

 an = Node(index, index);

 index++;

 for(auto b : gra[a]){

  Node &bn = nodes[b];

  if(bn.index == 0){

   strongconnect(b);

   an.lowlink = min(an.lowlink, bn.lowlink);

  }else{

   an.lowlink = min(an.lowlink, bn.index);

  }

 }

 if(an.index == an.lowlink){

  components.push_back(vector<int>());

  vector<int> &component = components.back();

  int b;

  do{

   b = s.top();

   s.pop();

   nodes[b].onstack = false;

   component.push_back(b);

  }while(b != a);

 }

}



void tarzan(){

 for(int i = 1; i <= n; ++i){

  if(nodes[i].index == 0){

   strongconnect(i);

   while(!s.empty()){

    components.push_back({s.top()});

    s.pop();

   }

  }

 }

}



void write(){

 fout << components.size() << "\n";

 for(auto component : components){

  for(auto a : component){

   fout << a << " ";

  }

  fout << "\n";

 }

}



int main(){

 read();

 tarzan();

 write();

 return 0;

}
