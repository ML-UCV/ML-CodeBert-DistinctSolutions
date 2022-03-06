#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int N = 200041;



struct edg{

 int a, b, v;

 bool operator<(const edg &rhs){

  return v < rhs.v;

 }

};



int n, m;

vector<edg> eg;

vector<edg> nice;



int tre[N];

int dad(int a){

 if(a != tre[a]){

  tre[a] = dad(tre[a]);

 }

 return tre[a];

}



void makeuni(int a, int b){

 tre[dad(a)] = dad(b);

}



bool chekuni(int a, int b){

 return dad(a) == dad(b);

}



int main(){



 fin >> n >> m;

 for(int i = 0; i < m; ++i){

  edg e;

  fin >> e.a >> e.b >> e.v;

  eg.push_back(e);

 }



 for(int i = 1; i <= n; ++i){

  tre[i] = i;

 }



 int cost = 0;

 sort(eg.begin(), eg.end());

 for(auto e : eg){

  if(!chekuni(e.a, e.b)){

   makeuni(e.a, e.b);

   cost += e.v;

   nice.push_back(e);

  }

 }



 fout << cost << "\n";

 fout << nice.size() << "\n";

 for(auto e : nice){

  fout << e.a << " " << e.b << "\n";

 }



 return 0;

}
