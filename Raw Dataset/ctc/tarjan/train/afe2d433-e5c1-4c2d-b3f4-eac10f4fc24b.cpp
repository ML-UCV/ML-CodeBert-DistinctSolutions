#include <iostream>
#include <fstream>
#include <vector>
#include <stack>


using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



int const NMAX = 1e5;

int n, m;

vector<int> g[1 + NMAX];

vector<int> scc[1 + NMAX];



int nComp;

stack<int> st;

int time1[1 + NMAX];

int lowLink[1 + NMAX];

int t = 0;

bool onStack[1 + NMAX];



void tarjan(int from) {



  t++;

  time1[from] = t;

  lowLink[from] = t;

  st.push(from);

  onStack[from] = true;

  for(int to : g[from]) {

    if(time1[to] == 0) {

      tarjan(to);

      lowLink[from] = min(lowLink[from], lowLink[to]);

    } else if(onStack[to]) {

      lowLink[from] = min(lowLink[from], lowLink[to]);

    }

  }



  if(lowLink[from] == time1[from]) {



    while(!st.empty() && lowLink[from] <= lowLink[st.top()]) {

      scc[nComp].push_back(st.top());

      onStack[st.top()] = false;

      st.pop();

    }



    nComp++;

  }

}



int main(){

  in >> n >> m;

  for(int i = 1; i <= m; i++) {

    int a, b;

    in >> a >> b;

    g[a].push_back(b);

  }

  for(int i = 1; i <= n; i++) {

    if(time1[i] == 0) {

      tarjan(i);

    }

  }

  out << nComp << "\n";

  for(int i = 0; i < nComp; i++) {

    for(int j = 0; j < scc[i].size(); j++) {

      out << scc[i][j] << " ";

    }

    out << "\n";

  }

}
