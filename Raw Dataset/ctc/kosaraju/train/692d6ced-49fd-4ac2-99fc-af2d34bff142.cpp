#include <stdio.h>
#include <cstring>
#include <vector>
#include <stack>




FILE* fin, * fout;



int n, m;

std::vector<int> G[100005], GT[100005];

int nr = 0;

std::vector<int> res[100005];

std::stack<int> s;

bool viz[100005];



void dfs(int u) {

 if (viz[u] == true)

  return;

 viz[u] = true;

 for (int v : G[u])

  dfs(v);

 s.push(u);

}



void dfs_t(int u) {

 if (viz[u] == true)

  return;

 viz[u] = true;

 res[nr].push_back(u);

 for (int v : GT[u])

  dfs_t(v);

}





int main() {

 fin = fopen("ctc.in", "r");

 fout = fopen("ctc.out", "w");



 fscanf(fin, "%i %i", &n, &m);



 while (m--) {

  int x, y;

  fscanf(fin, "%i %i", &x, &y);

  G[x].push_back(y);

  GT[y].push_back(x);

 }



 memset(viz, false, sizeof(viz));

 for (int i = 1;i <= n;++i)

  dfs(i);

 memset(viz, false, sizeof(viz));

 while (!s.empty()) {

  if (!viz[s.top()]) {

   dfs_t(s.top());

   ++nr;

  }

  s.pop();

 }



 fprintf(fout,"%i\n", nr);

 for (int i = 0;i < nr;++i) {

  for (int x : res[i])

   fprintf(fout,"%i ", x);

  fprintf(fout,"\n");

 }



 return 0;

}
