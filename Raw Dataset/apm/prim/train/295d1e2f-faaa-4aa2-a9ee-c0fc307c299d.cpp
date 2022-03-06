#include <cstdio>
#include <vector>
#include <utility>


using namespace std;







vector<vector<pair<int, int>>> arcs;

vector<pair<int, int>> usedArcs;

vector<int> heap, poz, inTreeCost, parents;



int heapSize;





void add_to_apm(int x) {

 for(int i=0; i<arcs[x].size(); ++i) {

  if (arcs[x][i].second <= inTreeCost[arcs[x][i].first]) {

   inTreeCost[arcs[x][i].first] = arcs[x][i].second;

   parents[arcs[x][i].first] = x;

  }

 }

}





void percolate(int current_node) {

 int aux;

 while(current_node > 1 && inTreeCost[heap[current_node]] < inTreeCost[heap[current_node / 2]]) {

  aux = heap[current_node];

  heap[current_node] = heap[current_node / 2];

  heap[current_node / 2] = aux;



  poz[heap[current_node]] = current_node;

  poz[heap[current_node / 2]] = current_node / 2;



  current_node /= 2;

 }

}





void sift(int current_node) {

 int aux, current_son = 1;

 while (current_son) {

  current_son = 0;

  if (current_node * 2 <= heapSize && inTreeCost[heap[current_node]] >inTreeCost[heap[current_node * 2]])

   current_son = current_node * 2;



  if (current_node * 2 + 1 <= heapSize && inTreeCost[heap[current_node]] > inTreeCost[heap[current_node * 2 + 1]] &&

   (current_son == 0 || inTreeCost[heap[current_son]] > inTreeCost[heap[current_node * 2 + 1]]))

   current_son = current_node * 2 + 1;



  if (current_son) {

   aux = heap[current_son];

   heap[current_son] = heap[current_node];

   heap[current_node] = aux;



   poz[heap[current_node]] = current_node;

   poz[heap[current_son]] = current_son;



   current_node = current_son;

  }

 }

}





void add_to_heap(int x) {

 ++heapSize;

 heap[heapSize] = x;

 poz[x] = heapSize;

 percolate(heapSize);

}





void delete_node(int current_node) {

    if (! heapSize)

        return;

 poz[heap[current_node]] = -1;

 heap[current_node] = heap[heapSize];

 poz[heap[current_node]] = current_node;

 --heapSize;



 if (current_node > 1 && inTreeCost[heap[current_node / 2]] > inTreeCost[heap[current_node]])

  percolate(current_node);

 else

  sift(current_node);



}





int main() {

 freopen("apm.in", "r", stdin);

 freopen("apm.out", "w", stdout);



 int n, m, a, b, c;

 scanf("%d%d", &n, &m);

 arcs.resize(n + 1);

 heap.resize(m * 2 + 10, 0);

 poz.resize(n + 1, 0);

 inTreeCost.resize(n+1, 1<<30);

 parents.resize(n+1, 0);



 for(int i=0; i<m; ++i) {

  scanf("%d%d%d", &a, &b, &c);

  arcs[a].push_back(pair<int, int>(b, c));

  arcs[b].push_back(pair<int, int>(a, c));

 }



 inTreeCost[1] = 0;

 add_to_apm(1);



 for(int i=2; i<=n; ++i)

  add_to_heap(i);



 c = 0;

 for(int i=1; i<n; ++i) {

  a = heap[1];

  delete_node(1);

  add_to_apm(a);

  c += inTreeCost[a];

  usedArcs.push_back(pair<int, int>(parents[a], a));



  for(int j=0; j<arcs[a].size(); ++j)

   if (poz[arcs[a][j].first] != -1)

    percolate(poz[arcs[a][j].first]);

 }



 printf("%d\n%d\n", c, usedArcs.size());

 for(int i=0; i<usedArcs.size(); ++i)

  printf("%d %d\n", usedArcs[i].first, usedArcs[i].second);



 return 0;

}
