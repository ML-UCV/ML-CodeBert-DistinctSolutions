#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
#include <cmath>
using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");
struct edge{

 int x;

 int y;

 int cost;

};

bool comparator(const edge& lhs, const edge& rhs)

{

 return lhs.cost < rhs.cost;

}



vector<edge> graph;

vector<pair<int, int>> solution;



int n, m, total = 0;

int t[200005], rang[200005];



void read()

{

 in >> n >> m;

 for (int i = 1; i <= m; i++)

 {

  int x, y, c;

  in >> x >> y >> c;

  graph.push_back({ x,y,c });





  t[i] = i;

  rang[i] = 1;

 }



 sort(graph.begin(), graph.end(), &comparator);



}



int find(int nod)

{

 while (t[nod] != nod)

  nod = t[nod];

 return nod;

}



void Union(int x, int y)

{

 if (rang[x] < rang[y])

  t[x] = y;



 if (rang[x] > rang[y])

  t[y] = x;



 if (rang[x] == rang[y])

 {

  t[x] = y;

  rang[y]++;

 }



}



void solve()

{

 for (const auto& e : graph)

 {

  int tatal_x = find(e.x);

  int tatal_y = find(e.y);



  if (tatal_x != tatal_y)

  {

   Union(tatal_x,tatal_y);

   solution.push_back({ e.x,e.y });

   total += e.cost;

  }

 }

}



void print()

{



 out << total << '\n';

 out << solution.size()<<'\n';



 for (const auto& p : solution)

 {

  out << p.first << ' ' << p.second << '\n';

 }

}

int main()

{

 read();

 solve();

 print();

}
