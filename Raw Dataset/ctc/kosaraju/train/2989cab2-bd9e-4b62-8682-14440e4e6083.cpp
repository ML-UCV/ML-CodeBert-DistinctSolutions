#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int NMAX = 100005;



int m, n;

vector<int>G[NMAX];

vector<int>Gt[NMAX];

vector<vector<int> >sol;

vector<int>v;

stack<int>st;

bool viz[NMAX];



void read()

{

 fin >> n >> m;

 while (m--)

 {

  int a, b;

  fin >> a >> b;

  G[a].push_back(b);

  Gt[b].push_back(a);

 }

}



void write()

{

 fout << sol.size() << "\n";

 for (vector<int>v : sol)

 {

  for (int it : v)

   fout << it << " ";

  fout << "\n";

 }

}



void dfs(int nod, stack<int>& st)

{

 viz[nod] = true;

 for (vector<int>::iterator it = G[nod].begin(); it != G[nod].end(); it++)

 {

  int nnod = *it;

  if (!viz[nnod])

   dfs(nnod, st);

 }

 st.push(nod);

}



void dfsT(int nod, vector<int> &v)

{

 viz[nod] = true;

 for (vector<int>::iterator it = Gt[nod].begin(); it != Gt[nod].end(); it++)

 {

  int nnod = *it;

  if (!viz[nnod])

   dfsT(nnod, v);

 }

 v.push_back(nod);

}



void solve()

{

 for (int i = 1; i <= n; i++)

  viz[i] = 0;



 for (int nod = 1; nod <= n; nod++)

  if (!viz[nod])

   dfs(nod, st);



 for (int i = 1; i <= n; i++)

  viz[i] = 0;



 while (!st.empty())

 {

  int nod = st.top();

  v.clear();

  st.pop();

  if (!viz[nod])

  {

   dfsT(nod, v);

   sort(v.begin(), v.end());

   sol.push_back(v);

  }

 }



}



int main()

{

 read();

 solve();

 write();

 return 0;

}
