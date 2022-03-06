#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <limits.h>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int N = 200005, INF = INT_MAX;



vector<pair<int, int>> g[N];

bool vizitat[N];

int CostMin[N];

int tata[N];



int main()

{

 int n, m;

 fin >> n >> m;



 for (int i = 0; i < m; i++)

 {

  int a, b, c;

  fin >> a >> b >> c;

  g[a].push_back({ b, c });

  g[b].push_back({ a, c });

 }



 for (int i = 2; i <= n; i++)

 {

  CostMin[i] = INF;

 }



 set<pair<int, int>> heap;

 heap.insert({ 0, 1 });



 int CostTotal = 0;

 while (!heap.empty())

 {



  int nod = heap.begin()->second;

  CostTotal += heap.begin()->first;

  heap.erase(heap.begin());

  vizitat[nod] = true;



  for (auto neigh : g[nod])

  {

   int NodVecin = neigh.first;

   int CostVecin = neigh.second;



   if (!vizitat[NodVecin] && CostVecin < CostMin[NodVecin])

   {

    if (CostMin[NodVecin] != INF)

    {

     heap.erase(heap.find({ CostMin[NodVecin], NodVecin }));

    }



    heap.insert({ CostVecin, NodVecin });

    CostMin[NodVecin] = CostVecin;

    tata[NodVecin] = nod;

   }

  }

 }



 fout << CostTotal << '\n' << n - 1 << '\n';

 for (int i = 2; i <= n; i++)

 {

  fout << i << ' ' << tata[i] << '\n';

 }

}
