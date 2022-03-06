#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



pair <int, int> fin[400001];



int n, m, T[200001], index;



struct Edge

{

 int i, j, cost;



}E[400001];



void read()

{

 f >> n >> m;



 for (int i = 1; i <= m; i++)



  f >> E[i].i >> E[i].j >> E[i].cost;

}



bool way(Edge a , Edge b)

{

 return a.cost < b.cost;

}



int find(int x)

{

 if (T[x] == x)return x;



 else



 {

  T[x] = find(T[x]);



  return T[x];

 }

}



void Union(int x, int y)

{

 T[x] = T[y];

}



void solve()

{

 sort(E + 1, E + m + 1, way);



 long s = 0;



 for (int i = 1; i <= n; i++)T[i] = i;



 for (int i = 1; i <= m; i++)

 {

  int x = find(E[i].i);

  int y = find(E[i].j);



  if (x != y)

  {

   Union(T[x], T[y]);



   fin[++index]=(make_pair(E[i].i, E[i].j));



   s += E[i].cost;

   }

   }

 g << s << '\n' << index << '\n';



 for (int i = 1; i <= index; i++)



  g << fin[i].first << " " << fin[i].second << '\n';

}

int main()

{

 read();

 solve();

}
