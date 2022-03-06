#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;



ifstream in("party.in");

ofstream out("party.out");



const int N = 105;



vector<int> g[2*N], gt[2*N], lst, finSol;

bool sol[2*N], vis[2*N];

int n, m;



void firstPass(int x) {

   vis[x] = 1;

   for(auto y : g[x]) {

      if(!vis[y]) {

         firstPass(y);

      }

   }

   lst.push_back(x);

}



void secondPass(int x) {

   vis[x] = 1;

   sol[(x <= n ? x + n : x - n)] = 1;

   for(auto y : gt[x]) {

      if(!vis[y]) {

         secondPass(y);

      }

   }

}



inline void addEdge(int x, int y, int t) {

   if(t == 0) {

      g[(x <= n ? x + n : x - n)].push_back(y);

      g[(y <= n ? y + n : y - n)].push_back(x);

      gt[y].push_back((x <= n ? x + n : x - n));

      gt[x].push_back((y <= n ? y + n : y - n));

   }

   else if(t == 1) {

      g[y].push_back(x);

      gt[x].push_back(y);

      g[(x <= n ? x + n : x - n)].push_back((y <= n ? y + n : y - n));

      gt[(y <= n ? y + n : y - n)].push_back((x <= n ? x + n : x - n));

   }

   else if(t == 2) {

      g[x].push_back(y);

      gt[y].push_back(x);

      g[(y <= n ? y + n : y - n)].push_back((x <= n ? x + n : x - n));

      gt[(x <= n ? x + n : x - n)].push_back((y <= n ? y + n : y - n));

   }

   else {

      g[x].push_back((y <= n ? y + n : y - n));

      gt[(y <= n ? y + n : y - n)].push_back(x);

   }

}



int main() {

   int i, x, y, t;



   in >> n >> m;

   for(i = 1; i <= m; i++) {

      in >> x >> y >> t;

      addEdge(x, y, t);

   }



   for(i = 1; i <= n; i++) {

      if(!vis[i]) {

         firstPass(i);

      }

   }

   fill(vis, vis + 2*N, 0);

   reverse(lst.begin(), lst.end());

   for(auto i : lst) {

      if(!vis[i] && !vis[(i <= n ? i + n : i - n)]) {

         secondPass(i);

      }

   }



   for(i = 1; i <= n; i++) {

      if(sol[i]) {

         finSol.push_back(i);

      }

   }



   out << finSol.size() << '\n';

   for(auto i : finSol) out << i << '\n';



   return 0;

}
