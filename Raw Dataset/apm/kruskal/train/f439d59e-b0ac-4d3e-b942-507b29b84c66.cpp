#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



vector<int> t;



int find(int x)

{

 if (t[x] == 0)

 {

  return x;

 }



 t[x] = find(t[x]);

 return t[x];

}



void unite(int x, int y)

{

 int rx = find(x);

 int ry = find(y);

 t[rx] = ry;

}



int main()

{

 int n, m;

 fin >> n >> m;



 t.resize(n + 1);

 vector<pair<int, pair<int, int>>> drumuri(m);



 for (int i = 0; i < m; i++)

 {

  int x, y, cost;

  fin >> x >> y >> cost;



  drumuri[i] = { cost, { x, y } };

 }



 sort(drumuri.begin(), drumuri.end());



 vector<pair<int, int>> muchii;

 int CostMin = 0;



 for (auto drum : drumuri)

 {

  int cost = drum.first;

  int x = drum.second.first;

  int y = drum.second.second;



  if (find(x) != find(y))

  {

   CostMin += cost;

   muchii.push_back({ x, y });

   unite(x, y);

  }

 }



 fout << CostMin << '\n' << n - 1 << '\n';

 for (auto muchie : muchii)

 {

  fout << muchie.first << ' ' << muchie.second << '\n';

 }



 return 0;

}
