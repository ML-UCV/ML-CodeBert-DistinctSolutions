#include <bits/stdc++.h>




using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m,nrc;

vector<int> edge[100001],revedge[100001];

vector<int>popn;

vector<int> ans[100001];

bitset<100001> viz;



void DFS(int x)

{

 viz[x] = 1;

 for (int i : edge[x])

  if (!viz[i])

   DFS(i);

 popn.push_back(x);

}

void DFSREV(int x)

{

 viz[x] = 1;

 ans[nrc - 1].push_back(x);

 for (int i : revedge[x])

  if (!viz[i])

   DFSREV(i);

}

int main()

{

 int x, y;

 fin >> n >> m;

 while (m--)

 {

  fin >> x >> y;

  edge[x].push_back(y);

  revedge[y].push_back(x);

 }

 for(int i = 1; i <= n; i++)

  if (!viz[i])

   DFS(i);

 viz.reset();

 for(vector<int>::reverse_iterator it = popn.rbegin(); it != popn.rend(); it++)

  if (!viz[*it])

  {

   nrc++;

   DFSREV(*it);

  }



 fout << nrc << "\n";

 for (int i = 0; i <= ans->size(); i++)

  sort(ans[i].begin(), ans[i].end());

 for (int i = 0; i < nrc; i++) {

  for (int j : ans[i])

   fout << j << " ";

  fout << "\n";

 }



 fin.close();

 fout.close();

 return 0;

}
