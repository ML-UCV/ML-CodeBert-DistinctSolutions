#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>


using namespace std;

fstream f("apm.in");

ofstream o("apm.out");

int n, m;



class node

{

public:

 int source, dest, cost;



 node()

 {



 }



};



node g[200005];

int parinte[200005];

node out[200005];

int sz;



int Find(int x)

{

 int y = x, t;

 while (parinte[y] != y)

 {

  y = parinte[y];

 }



 while (x != y)

 {

  t = parinte[x];

  parinte[x] = y;

  x = t;

 }

 return x;



}





void Union(int x, int y)

{

 x = Find(x);

 y = Find(y);



 if (x != y)

 {

  parinte[y] = x;

 }

}



int apm_kruskal()

{

 int cost = 0;



 for (size_t i = 0; i < m; i++)

 {

  if (Find(g[i].source) != Find(g[i].dest))

  {

   Union(g[i].source, g[i].dest);

   cost += g[i].cost;

   out[sz++] = g[i];

  }

 }

 return cost;

}



int main()

{

 f >> n >> m;

 for (size_t i = 0; i < m; i++)

 {

  int x, y, cost;

  f >> x >> y >> cost;

  g[i].source = x;

  g[i].dest = y;

  g[i].cost = cost;

 }



 for (size_t i = 1; i <= n; i++)

 {

  parinte[i] = i;

 }



 sort(g, g + m, [](node cost1, node cost2)

 {

  return cost1.cost < cost2.cost;

 });



 o << apm_kruskal() << "\n";

 o << sz << "\n";

 for (size_t i = 0; i < sz; i++)

 {

  o << out[i].dest << " " << out[i].source << "\n";

 }



}
