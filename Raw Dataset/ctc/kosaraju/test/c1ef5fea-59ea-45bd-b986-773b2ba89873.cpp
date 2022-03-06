#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int NMAX = 1e5 + 5;



int ctc;

vector<int> g[NMAX], tr[NMAX], rez[NMAX];

vector<int> viz(NMAX);

stack<int> po;



void DFS(int nod)

{

 viz[nod] = 1;

 for (size_t i = 0; i < g[nod].size(); ++i)

  if (!viz[g[nod][i]]) DFS(g[nod][i]);

 po.push(nod);

}



void DFST(int nod)

{

 viz[nod] = 0, rez[ctc].push_back(nod);

 for (size_t i = 0; i < tr[nod].size(); ++i)

  if (viz[tr[nod][i]] == 1) DFST(tr[nod][i]);

}



int main()

{

 ios::sync_with_stdio(false);

 fin.tie(0);



 int n, m;

 fin >> n >> m;



 while (m--)

 {

  int x, y;

  fin >> x >> y;



  g[x].push_back(y), tr[y].push_back(x);

 }



 for (int i = 1; i <= n; ++i)

  if (!viz[i]) DFS(i);



 while (!po.empty())

 {

  if (viz[po.top()] == 1)

  {

   ++ctc;

   DFST(po.top());

  }

  po.pop();

 }



 fout << ctc << "\n";



 for (int i = 1; i <= ctc; ++i)

 {

  for (size_t j = 0; j < rez[i].size(); ++j)

   fout << rez[i][j] << " ";

  fout << "\n";

 }



 return 0;

}
