#include <bits/stdc++.h>




using namespace std;



struct edge {

 int x;

 int y;

 int c;

};



bool cmp(const struct edge& edge1, const struct edge& edge2) {

    return edge1.c < edge2.c;

}



int n, m, cost_apm;

int root[200010];

vector<edge> edges;

vector<edge> apm;



void read_input() {

 ifstream fin("apm.in");



 fin >> n >> m;



 for (int i = 1; i <= m; ++i) {

  int x, y, c;

  fin >> x >> y >> c;



  struct edge to_be_added;

  to_be_added.x = x;

  to_be_added.y = y;

  to_be_added.c = c;



  edges.push_back(to_be_added);

 }



 fin.close();

}



int get_set(int node) {

   if (root[node] != node) {

     root[node] = get_set(root[node]);

   }



   return root[node];

}



void reunion_set(int x, int y) {

 root[get_set(x)] = get_set(y);

}



void Kruskal() {

 sort(edges.begin(), edges.end(), cmp);



 for (int i = 1; i <= n; ++i) {

  root[i] = i;

 }



 cost_apm = 0;



 for (auto &edge : edges) {

  if (get_set(edge.x) != get_set(edge.y)) {

   cost_apm += edge.c;

   apm.push_back(edge);

   reunion_set(edge.x, edge.y);

  }

 }

}



void print_output() {

 ofstream fout("apm.out");



 fout << cost_apm << "\n";

 fout << apm.size() << "\n";



 for (auto &edge : apm) {

  fout << edge.x << " " << edge.y << "\n";

 }



 fout.close();

}







int main() {

 read_input();

 Kruskal();

 print_output();



 return 0;

}
