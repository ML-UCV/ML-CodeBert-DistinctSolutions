#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <limits.h>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int N = 200005;



vector<pair<int, int>> g[N];

int CostMin[N];

bool vizitat[N];

int tata[N];



int main()

{

 int n, m;

 fin >> n >> m;



 for (int i = 0; i < m; i++)

 {

  int x, y, c;

  fin >> x >> y >> c;

  g[x].push_back({ y, c });

  g[y].push_back({ x, c });

 }



 for (int i = 2; i <= n; i++)

 {

  CostMin[i] = INT_MAX;

 }



 priority_queue<pair<int, int>> heap;

 heap.push({ 0, 1 });



 int CostTotal = 0;

 while (!heap.empty())

 {

  int nod = heap.top().second;

  int cost = heap.top().first;

  heap.pop();



  if (vizitat[nod])

  {

   continue;

  }



  vizitat[nod] = true;

  CostTotal -= cost;



  for (auto neigh : g[nod])

  {

   if (!vizitat[neigh.first] && neigh.second < CostMin[neigh.first])

   {

    heap.push({ -neigh.second, neigh.first });

    CostMin[neigh.first] = neigh.second;

    tata[neigh.first] = nod;

   }

  }

 }



 fout << CostTotal << '\n' << n - 1 << '\n';

 for (int i = 2; i <= n; i++)

 {

  fout << i << ' ' << tata[i] << '\n';

 }

}
