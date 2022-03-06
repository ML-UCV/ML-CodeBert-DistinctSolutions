#include <cmath>
#include <fstream>
#include <queue>
#include <vector>


using namespace std;



struct Nod

{

 double cost = (1 << 30);

 vector<pair<int, double>> vecini;

};



typedef vector<Nod> Graf;

typedef pair<int, double> Pereche;



const int kMod = 104659;

const double kEpsilon = 0.00001;



inline double Log2(int n)

{

 return log(n) / log(2);

}



void AflaDistante(Graf &g)

{

 auto cmp = [](const Pereche &a, const Pereche &b) -> bool { return a.second > b.second; };

 priority_queue<Pereche, vector<Pereche>, decltype(cmp)> coada(cmp);



 g[1].cost = 0;

 coada.push({ 1, 0 });



 while (!coada.empty()) {

  int nod = coada.top().first;

  double cost = coada.top().second;

  coada.pop();



  if (cost != g[nod].cost) continue;



  for (auto &muchie : g[nod].vecini) {

   int vecin = muchie.first;

   double cost_nou = cost + muchie.second;

   if (g[vecin].cost - cost_nou > kEpsilon) {

    g[vecin].cost = cost_nou;

    coada.push({ vecin, cost_nou });

   }

  }

 }

}



vector<int> AflaModuri(const Graf &g)

{

 vector<int> moduri(g.size(), 0);

 queue<int> coada;

 vector<bool> in_coada(g.size(), false);



 coada.push(1);

 moduri[1] = 1;

 in_coada[1] = true;



 while (!coada.empty()) {

  int nod = coada.front();

  coada.pop();



  for (auto &muchie : g[nod].vecini) {

   int vecin = muchie.first;

   if (abs(g[vecin].cost - g[nod].cost - muchie.second) <= kEpsilon && g[vecin].cost - g[nod].cost > kEpsilon) {

    moduri[vecin] += moduri[nod];

    moduri[vecin] %= kMod;

    if (!in_coada[vecin]) {

     coada.push(vecin);

     in_coada[vecin] = true;

    }

   }

  }

 }

 return moduri;

}



int main()

{

 ifstream fin("dmin.in");

 ofstream fout("dmin.out");



 int n, m;

 fin >> n >> m;



 Graf graf(n + 1);

 while (m--) {

  int x, y, c;

  fin >> x >> y >> c;



  double cost = Log2(c);

  graf[x].vecini.push_back({ y, cost });

  graf[y].vecini.push_back({ x, cost });

 }



 AflaDistante(graf);



 auto raspuns = AflaModuri(graf);

 for (int i = 2; i < raspuns.size(); ++i)

  fout << raspuns[i] << " ";



 return 0;

}
