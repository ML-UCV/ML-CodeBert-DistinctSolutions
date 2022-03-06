#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;



struct Arc {

 int x, y, cost;

 Arc(int x, int y, int cost) {

  this->x = x;

  this->y = y;

  this->cost = cost;

 }

};



vector <bool> selectedArcs;

vector <Arc> arcs;

vector <int> forest;



bool comp(Arc a, Arc b) {

 return a.cost < b.cost;

}





int get(int i) {

 if (forest[i] == i)

  return i;

 forest[i] = get(forest[i]);

 return forest[i];

}





void add (int i, int j) {

 forest[get(i)] = get(j);

}





int main() {

 freopen("apm.in", "r", stdin);

 freopen("apm.out", "w", stdout);



 int n, m, a, b, c;

 scanf("%d%d", &n, &m);



 selectedArcs.resize(m+1, 0);

 forest.resize(n+1);



 for(int i=0; i<m; ++i) {

  scanf("%d%d%d", &a, &b, &c);

  arcs.push_back(Arc(a, b, c));

 }



 for(int i=1; i<=n; ++i)

  forest[i] = i;

 sort(arcs.begin(), arcs.end(), comp);



 a = c = 0;

 for(int i=0; i<m; ++i) {

  if (get(arcs[i].x) != get(arcs[i].y)) {

   ++ a;

   c += arcs[i].cost;



   add(arcs[i].x, arcs[i].y);

   selectedArcs[i] = true;

  }

 }



 printf("%d\n%d\n", c, a);



 for(int i=0; i<m; ++i)

  if (selectedArcs[i])

   printf("%d %d\n", arcs[i].x, arcs[i].y);



 return 0;

}
