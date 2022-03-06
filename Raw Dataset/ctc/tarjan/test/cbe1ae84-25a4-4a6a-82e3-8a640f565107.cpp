#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");







int index, scc;

vector<int> g[100005], ids, lowlink, temp;

vector<vector<int>> sol;

stack<int> s;

vector<bool> inStack;

int n, m;





void read()

{

 for (in >> n >> m; m--;)

 {

  int x, y;

  in >> x >> y;

  g[x].push_back(y);

 }

 ids.resize(n + 5), ids.assign(n + 5, -1);

 inStack.resize(n + 5), inStack.assign(n + 5, 0);

 lowlink.resize(n + 5);

}





void tarjan(int node)

{

 ids[node] = lowlink[node] = index++;

 s.push(node);

 inStack[node] = true;



 for (int it = 0; it < g[node].size(); it++)

 {

  int adjNode = g[node][it];

  if (ids[adjNode] == -1)

  {

   tarjan(adjNode);

   lowlink[node] = min(lowlink[node], lowlink[adjNode]);

  }

  else if (inStack[adjNode])

   lowlink[node] = min(lowlink[node], lowlink[adjNode]);

 }



 if (ids[node] == lowlink[node])

 {

  temp.clear();

  int nd;

  do

  {

   nd = s.top();

   temp.push_back(nd);

   s.pop();

   inStack[nd] = false;



  } while (nd != node);

  sol.push_back(temp);

 }

}



void print()

{

 out << sol.size() << '\n';

 for (vector<int> it : sol)

 {

  copy(it.begin(), it.end(), ostream_iterator<int>(out, " "));

  out << '\n';

 }

}



void solve()

{

 read();

 for (int i = 1; i <= n; i++)

  if (ids[i] == -1)

   tarjan(i);



 print();

}



int main()

{

 solve();

}
