#include <fstream>
#include <algorithm>


using namespace std;



struct muchie {

 int cost;

 int a, b;

 bool operator<(const muchie& alt) const {

  return this->cost < alt.cost;

 }

};



const int N = 2e5 + 1, M = 4e5;



int sef[N];

muchie mc[M], rez[N];



int sefsuprem(int nod) {

 if (sef[nod] == nod)

  return nod;

 return sef[nod] = sefsuprem(sef[nod]);

}



bool unire(int a, int b) {

 int sef_a, sef_b;

 sef_a = sefsuprem(a);

 sef_b = sefsuprem(b);

 if (sef_a == sef_b)

  return false;

 sef[sef_a] = sef_b;

 return true;

}



int main() {

 ifstream in("apm.in");

 ofstream out("apm.out");



 int n, m;

 in >> n >> m;

 for (int i = 1; i <= n; ++i)

  sef[i] = i;

 for (int i = 0; i < m; ++i)

  in >> mc[i].a >> mc[i].b >> mc[i].cost;

 sort(mc, mc + m);

 int poz = 0, cost = 0;

 for (int i = 0; i < n - 1; ++i) {

  while (!unire(mc[poz].a, mc[poz].b))

   ++poz;

  cost += mc[poz].cost;

  rez[i] = mc[poz];

  ++poz;

 }

 out << cost << '\n' << n - 1 << '\n';

 for (int i = 0; i < n - 1; ++i)

  out << rez[i].a << ' ' << rez[i].b << '\n';



 in.close();

 out.close();

 return 0;

}
