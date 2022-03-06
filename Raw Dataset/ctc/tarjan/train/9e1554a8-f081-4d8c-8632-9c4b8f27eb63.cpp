#include <iostream>
#include <fstream>
#include <vector>
#include <stack>


using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



int const NMAX = 1e5;

vector <int> g[1 + NMAX];

vector <int> strongA[1 + NMAX];int strAsiz;

int visited[1 + NMAX];

int minReach[1 + NMAX];

bool onStack[1 + NMAX];

stack <int> st;



int n, m, step;



void strong(int nod) {



  step++;

  visited[nod] = step;

  minReach[nod] = step;

  st.push(nod);

  onStack[nod] = true;



  for(int i = 0;i < g[nod].size();i++){





   if(visited[g[nod][i]] == 0){



     strong(g[nod][i]);

     minReach[nod] = min(minReach[nod], minReach[g[nod][i]]);

   }else if(onStack[g[nod][i]] == true){



     minReach[nod] = min(minReach[nod], visited[g[nod][i]]);

   }

  }

  if(minReach[nod] == visited[nod]){

    strAsiz++;

    int popped;

    do{



     popped = st.top();



     st.pop();



     onStack[popped] = false;

     strongA[strAsiz].push_back(popped);

   } while(popped != nod);

  }



}



int main(){



  int from, to;

  in >> n >> m;



  for(int i = 1;i <= m;i++){



   in >> from >> to;

   g[from].push_back(to);

  }



  for(int i = 1;i <= n;i++){



   if(visited[i] == 0) {

     strong(i);

   }

  }



  out << strAsiz << '\n';

  for(int i = 1;i <= strAsiz;i++){



   for(int j = 0;j < strongA[i].size() ;j++){

      out << strongA[i][j] << ' ';

   }

   out << '\n';

  }

  return 0;

}
