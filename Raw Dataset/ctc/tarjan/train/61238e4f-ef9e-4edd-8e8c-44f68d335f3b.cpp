#include <iostream>
#include <fstream>
#include <vector>
#include <stack>


using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



int const NMAX = 1e5;



struct Node {

  int visited;

  int minReach;

  bool onStack;

};



int n, m;

int strongSiz;



Node v[1 + NMAX];

vector <int> g[1 + NMAX];

vector <int> strong[1 + NMAX];

stack<int> st;



int step = 0;



void computeStrong(int from) {

  step++;

  v[from].visited = step;

  v[from].minReach = from;

  st.push(from);

  v[from].onStack = true;

  for(int i = 0; i < g[from].size(); i++) {

    int to = g[from][i];

    if(v[to].visited == 0){

      computeStrong(to);

      if(v[v[from].minReach].visited > v[v[to].minReach].visited) {

        v[from].minReach = v[to].minReach;

      }

    } else if(v[to].onStack == true) {

      if(v[v[from].minReach].visited > v[to].visited) {

        v[from].minReach = to;

      }

    }

  }

  if(v[from].minReach == from) {

    strongSiz++;

    int popped;

    do {

      popped = st.top();

      st.pop();

      strong[strongSiz].push_back(popped);

      v[popped].onStack = false;

    } while (popped != from);

  }

}



int main() {



  int a, b;

  in >> n >> m;

  for(int i = 1; i <= m; i++) {

    in >> a >> b;

    g[a].push_back(b);

  }

  for(int i = 1; i <= n; i++) {

    if(v[i].visited == 0) {

      computeStrong(i);

    }

  }

  out << strongSiz << '\n';

  for(int i = 1; i <= strongSiz; i++) {

    for(int j = 0; j < strong[i].size(); j++) {

      out << strong[i][j] << ' ';

    }

    out << '\n';

  }

  return 0;

}
