#include <fstream>
#include <vector>
#include <stack>


using namespace std;



vector<vector<int>> arcs;

vector<int> lowlink, index;

vector<bool> onStack;



vector<vector<int>> components;



stack<int> st;



int currentComp;



int min(int x, int y) {

 return x<y? x:y;

}



void strongConnect(int x) {

 st.push(x);



 ++currentComp;

 lowlink[x] = currentComp;

 index[x] = currentComp;

 onStack[x] = true;



 for(int i=0; i<arcs[x].size(); ++i) {

        int nextNode = arcs[x][i];

  if (! index[nextNode]) {

   strongConnect(nextNode);

   lowlink[x] = min(lowlink[x], lowlink[nextNode]);

  } else

   if (onStack[nextNode])

    lowlink[x] = min(lowlink[x], index[nextNode]);

 }



 if (lowlink[x] == index[x]) {

        components.push_back(vector<int>());



        int n;

  do {

      n = st.top();

   onStack[st.top()] = false;

   st.pop();



   components[components.size() - 1].push_back(n);

  } while (n != x);

 }

}





int main() {

    ifstream in("ctc.in");

    ofstream out("ctc.out");

 int n, m, x, y;

 in >> n >> m;



 arcs.resize(n+2);

 lowlink.resize(n+2, 0);

 index.resize(n+2, 0);

 onStack.resize(n+2, false);



 for(int i=0; i<m; ++i) {

  in >> x >> y;

  arcs[x].push_back(y);

 }



 for(int i=1; i<=n; ++i)

  if (index[i] == 0)

   strongConnect(i);



 out << components.size() << "\n";

 for(int i=0; i<components.size(); ++i) {

  for(int j=0; j<components[i].size(); ++j)

    out << components[i][j] << " ";

  out << "\n";

 }



 return 0;

}
