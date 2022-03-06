#include <bits/stdc++.h>

using namespace std;


ifstream fin("party.in");
ofstream fout("party.out");

const int NMAX = 102;

int n; int m;

vector<int> g[NMAX * 2];
vector<int> gt[NMAX * 2];

int ord[NMAX * 2]; int viz[NMAX * 2];

int solved[NMAX * 2];

bool existSolution = true;

int cnt;

int neg(int x) {

 if(x + n == 2 * n)
  return 2 * n;

 return (x + n) % (2 * n);
}

void read() {

 fin >> n >> m;

 for(int i = 1; i <= m ; ++i) {

  int x; int y; int z;
  fin >> x >> y >> z;



  if(z == 1)
   y = neg(y);

  if(z == 2)
   x = neg(x);

  if(z == 3)
   x = neg(x), y = neg(y);

  g[neg(x)].push_back(y);
  g[neg(y)].push_back(x);

  gt[y].push_back(neg(x));
  gt[x].push_back(neg(y));
 }


}

void dfs(int node) {

 viz[node] = 1;

 for(int x : g[node])
  if(viz[x] == 0)
   dfs(x);

 ord[++ord[0]] = node;
}

void dfsT(int node) {

 if(solved[node] == 1)
  existSolution = false;

 viz[node] = 1;
 solved[node] = 0;
 solved[neg(node)] = 1;

 for(int x : gt[node])
  if(viz[x] == 0)
   dfsT(x);
}

void solve() {



 for(int i = 1; i <= 2 * n; ++i)
  if(viz[i] == 0)
   dfs(i);

 memset(viz, 0, sizeof(viz));




 for(int i = ord[0]; i ; --i)
  if(viz[ord[i]] == 0 && viz[ neg(ord[i]) ] == 0)
   dfsT(ord[i]);

 for(int i = 1; i <= n ; ++i)
  if(solved[i] == 1)
   cnt++;

 fout << cnt << '\n';

 for(int i = 1; i <= n; ++i)
  if(solved[i] == 1)
   fout << i << '\n';

}

int main() {

 read();

 solve();

 return 0;
}
