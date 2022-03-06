#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;



const int NMAX = 100001;

int id=0, tot=0;

string resp="";

vector<int> graf[NMAX];

int ids[NMAX];

int low[NMAX];

bool onStack[NMAX];

stack<int> s;



void DFS(int curr) {

 onStack[curr] = true;

 ids[curr] = ++id;

 low[curr] = id;

 s.push(curr);

 for (int i = 0; i < graf[curr].size(); i++) {

  if (ids[graf[curr][i]] == 0) {

   DFS(graf[curr][i]);

  }

  if (onStack[graf[curr][i]]) {

   low[curr] = min(low[curr], low[graf[curr][i]]);

  }

 }



 if (ids[curr] == low[curr]) {

  while (!s.empty()) {

   int node = s.top();

   resp += to_string(node);

   resp += " ";

   s.pop();

   onStack[node] = false;

   low[node] = ids[curr];

   if (node == curr) {

    break;

   }

  }

  tot++;

  resp += "\n";

 }

}



int main() {

 ifstream in("ctc.in");

 ofstream out("ctc.out");

 int n, m, x, y;

 in >> n >> m;



 for (int i = 0; i < m; i++) {

  in >> x >> y;

  graf[x].push_back(y);

 }



 for (int i = 1; i <= n; i++) {

  if (ids[i] == 0) {

   DFS(i);

  }

 }



 out << tot << "\n" << resp;

 return 0;

}
