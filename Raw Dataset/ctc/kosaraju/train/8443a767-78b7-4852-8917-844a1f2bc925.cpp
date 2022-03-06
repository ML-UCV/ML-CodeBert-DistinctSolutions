#include <bits/stdc++.h>




using namespace std;

const int MAXN = (int) 1e5;

 vector <int> g[MAXN + 1], gr[MAXN + 1];
bool vis[MAXN + 1];
vector <int> top;

void dfs(int nod) {
 vis[nod] = 1;
 for(auto it : g[nod]) {
  if(vis[it] == 0) {
   dfs(it);
  }
 }
 top.push_back(nod);
}

vector <vector <int>> sol;

void dfs1(int nod) {
 sol.back().push_back(nod);
 vis[nod] = 1;
 for(auto it : gr[nod]) {
  if(vis[it] == 0) {
   dfs1(it);
  }
 }
}

int main() {




 ifstream cin("ctc.in");
 ofstream cout("ctc.out");
 int i, n, m;
 ios::sync_with_stdio(false);
 cin.tie(0), cout.tie(0);

 cin >> n >> m;
 for(i = 1; i <= m; i++) {
  int x, y; cin >> x >> y;
  g[x].push_back(y);
  gr[y].push_back(x);
 }
 for(i = 1; i <= n; i++) {
  if(vis[i] == 0) {
   dfs(i);
  }
 }
 memset(vis, 0, sizeof(vis));
 while(top.size()) {
  if(vis[top.back()] == 0) {
   sol.push_back(vector <int>());
   dfs1(top.back());
  }
  top.pop_back();
 }

 cout << sol.size() << "\n";
 for(auto &it : sol) {
  for(auto nod : it) {
   cout << nod << " ";
  }
  cout << "\n";
 }

 return 0;
}
