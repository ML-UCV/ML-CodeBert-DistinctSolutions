#include <bits/stdc++.h>






using namespace std;





typedef tuple<int, int> edge;
int n, m, cost_apm, root;

int dist[200010], parent[200010];

vector<edge> G[200010];

vector<edge> apm;

priority_queue<edge, vector<edge>, std::greater<edge>> pq;

bitset<200010> used;



void read_input() {

 ifstream fin("apm.in");



 fin >> n >> m;



 for (int i = 1; i <= m; ++i) {

  int x, y, c;

  fin >> x >> y >> c;



  G[x].push_back(edge(c, y));

  G[y].push_back(edge(c, x));

 }



 fin.close();

}



void Prim() {

 for (int i = 1; i <= n; ++i) {

  dist[i] = (1 << 30);

  parent[i] = 0;

 }



 root = 1;

 dist[root] = 0;

 parent[root] = 0;



 pq.push(edge(dist[root], root));



 cost_apm = 0;



 for (int i = 1; i <= n; ++i) {

        std::tuple<int, int> e;

        int node;



        do {

         e = pq.top();

         pq.pop();



         node = std::get<1>(e);

        } while (used[node]);



        cost_apm += dist[node];

        used[node] = 1;



        for (auto it = G[node].begin(); it != G[node].end(); ++it) {

            int neighbour = std::get<1>(*it), cost = std::get<0>(*it);



            if (!used[neighbour] && cost < dist[neighbour]) {

                dist[neighbour] = cost;

                parent[neighbour] = node;

                pq.push(edge(dist[neighbour], neighbour));

            }

        }

    }

}



void print_output() {

 ofstream fout("apm.out");



 fout << cost_apm << "\n";

 fout << (n - 1) << "\n";



 for (int i = 1; i <= n; ++i) {

  if (i != root) {

   fout << i << " " << parent[i] << "\n";

  }

 }



 fout.close();

}







int main() {

 read_input();

 Prim();

 print_output();



 return 0;

}
